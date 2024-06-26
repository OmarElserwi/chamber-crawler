#include "../Headers/controller.h"
#include "../Headers/atkdownpotion.h"
#include "../Headers/atkuppotion.h"
#include "../Headers/defdownpotion.h"
#include "../Headers/defuppotion.h"
#include "../Headers/door.h"
#include "../Headers/dragontreasure.h"
#include "../Headers/drow.h"
#include "../Headers/floor.h"
#include "../Headers/goblin.h"
#include "../Headers/hpdownpotion.h"
#include "../Headers/hpuppotion.h"
#include "../Headers/hwall.h"
#include "../Headers/merchanttreasure.h"
#include "../Headers/none.h"
#include "../Headers/normaltreasure.h"
#include "../Headers/passage.h"
#include "../Headers/shade.h"
#include "../Headers/smalltreasure.h"
#include "../Headers/staircase.h"
#include "../Headers/troll.h"
#include "../Headers/vampire.h"
#include "../Headers/vwall.h"
#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::make_unique;
using std::stringstream;
using namespace Utility;

Controller::Controller()
    : m_model{make_unique<Model>()}, text_view{make_unique<TextView>()} {}

void Controller::parseLayout(string file) {
  ifstream inFile(file);
  string line;
  if (inFile.is_open()) {
    while (getline(inFile, line)) {
      for (char c : line)
        switch (c) {
        case '.':
          m_model->generateTile<Floor>();
          break;
        case '#':
          m_model->generateTile<Passage>();
          break;
        case '+':
          m_model->generateTile<Door>();
          break;
        case '-':
          m_model->generateTile<HWall>();
          break;
        case '|':
          m_model->generateTile<VWall>();
          break;
        default:
          m_model->generateTile<None>();
        }
    }
    inFile.close();
  }
}

void Controller::findEnemies(string file) {
  ifstream inFile(file);
  string line;
  int count = 0;
  if (inFile.is_open()) {
    while (getline(inFile, line)) {
      for (char c : line)
        switch (c) {
        case '0':{
          m_model->generateEntity<HpDownPotion>(
              Loc(count % BOARD_WIDTH, count / BOARD_WIDTH));
          m_model->present_potions++;
        }break;
        case '1':{
          m_model->generateEntity<AtkUpPotion>(
              Loc(count % BOARD_WIDTH, count / BOARD_WIDTH));
          m_model->present_potions++;
        }break;
        case '2':{
          m_model->generateEntity<DefUpPotion>(
              Loc(count % BOARD_WIDTH, count / BOARD_WIDTH));
          m_model->present_potions++;
        }break;
        case '3':{
          m_model->generateEntity<HpDownPotion>(
              Loc(count % BOARD_WIDTH, count / BOARD_WIDTH));
          m_model->present_potions++;
        }break;
        case '4':{
          m_model->generateEntity<AtkDownPotion>(
              Loc(count % BOARD_WIDTH, count / BOARD_WIDTH));
        }break;
        case '5':{
          m_model->generateEntity<DefDownPotion>(
              Loc(count % BOARD_WIDTH, count / BOARD_WIDTH));
          m_model->present_potions++;
        }break;
        case '6':{
          m_model->generateEntity<NormalTreasure>(
              Loc(count % BOARD_WIDTH, count / BOARD_WIDTH));
          m_model->present_treasure++;
        }break;
        case '7':{
          m_model->generateEntity<SmallTreasure>(
              Loc(count % BOARD_WIDTH, count / BOARD_WIDTH));
          m_model->present_treasure++;
        }break;
        case '8':{
          m_model->generateEntity<MerchantTreasure>(
              Loc(count % BOARD_WIDTH, count / BOARD_WIDTH));
          m_model->present_treasure++;
        }break;
        case '9':{
          Loc dragon_treasure = m_model->generateEntity<DragonTreasure>(
              Loc(count % BOARD_WIDTH, count / BOARD_WIDTH));
          m_model->generateDragon(dragon_treasure);
          m_model->present_treasure++;
        }break;
        default:
          break;
        }
      ++count;
    }
  }
  inFile.close();
}

void Controller::parseNewGame() {
  m_model->resetTurnDesc();
  string cmd;
  cout << "Enter your Type:" << endl;
  cin >> cmd;
  m_model->generateChambers();
  switch (cmd[0]) {
  case 's':
    m_model->generatePlayer<Shade>();
    break;
  case 'd':
    m_model->generatePlayer<Drow>();
    break;
  case 'v':
    m_model->generatePlayer<Vampire>();
    break;
  case 't':
    m_model->generatePlayer<Troll>();
    break;
  case 'g':
    m_model->generatePlayer<Goblin>();
    break;
  default:
    m_model->generatePlayer<Shade>();
    break;
  }
  m_model->generateLevel();
  text_view->render(m_model.get());
  while (getline(cin, cmd)) {
    if (!parseTurn(cmd)) {
      break;
    }
  }
}

bool Controller::parseTurn(string cmd) {
  stringstream ss{cmd};
  string arg;
  ss >> arg;
  // If arg is not one letter, interpret it as a direction.
  if (arg.size() > 1) {
    m_model->playerMove(Utility::strToDirection(arg));
  } else {
    switch (arg.front()) {
    case 'f':
      if (m_model->getEnemyMovement()) {
        m_model->setEnemyMovement(false);
      } else {
        m_model->setEnemyMovement(true);
      }
      break;
    case 'r':
      text_view->displayFinalScore(m_model->getPlayer()->getScore());
      setRestart(true);
      return false;
      break;
    case 'q':
      text_view->displayScreen("Sources/gameoverscreen.txt");
      text_view->displayFinalScore(m_model->getPlayer()->getScore());
      setQuit(true);
      return false;
      break;
    case 'u':
      ss >> arg;
      m_model->playerUse(Utility::strToDirection(arg));
      break;
    case 'a':
      ss >> arg;
      m_model->playerAttack(Utility::strToDirection(arg));
    default:
      break;
    }
  }
  if (m_model->toNextFloor()) {
    m_model->nextFloor();
    if (m_model->getFloor() == 6) {
      text_view->displayScreen("Sources/winscreen.txt");
      text_view->displayFinalScore(m_model->getPlayer()->getScore());
      return false;
    }
    m_model->generateLevel();
    text_view->render(m_model.get());
    m_model->setNextFloor(false);
  } else {
    m_model->enemyTurn(m_model->getEnemyMovement());
    text_view->render(m_model.get());
  }
  if (m_model->getPlayer()->getHp() < 0) {
    text_view->displayScreen("Sources/gameoverscreen.txt");
    text_view->displayFinalScore(m_model->getPlayer()->getScore());
    return false;
  }
  m_model->resetTurnDesc();
  return true;
}

void Controller::restartGame() {
  text_view->displayScreen("Sources/restartscreen.txt");
}