#include <iostream>
using namespace std;

struct Character {
  char character;
  Character* next_char;
  Character* prev_char;
} node[200001];

Character* head;
Character* tail;
Character* cursor;

void init() {
  head = new Character();
  head->character = '$', head->next_char = head->prev_char = nullptr;
  tail = new Character();
  tail->character = '$', tail->next_char = tail->prev_char = nullptr;

  head->next_char = tail;
  tail->prev_char = head;
  cursor = tail;
}

char putString(char mStr[]) {
  int i = 0;
  while (mStr[i] != '\0') {
    if (mStr[i] == 'R') {
      int cmd_cnt = mStr[++i] - '0';

      for (int j = 0; j < cmd_cnt; j++) {
        if (cursor == tail) break;
        cursor = cursor->next_char;
      }
    } else if (mStr[i] == 'L') {
      int cmd_cnt = mStr[++i] - '0';

      for (int j = 0; j < cmd_cnt; j++) {
        if (cursor->prev_char == head) break;
        cursor = cursor->prev_char;
      }
    } else if (mStr[i] == 'F') {
      int cmd_cnt = mStr[++i] - '0';
      auto current = cursor;

      if (current->character >= 'a' && current->character <= 'z') {
        while (current->character != '_' && current != tail) {
          current = current->next_char;
        }
      }

      if (current != tail) {
        while (current != tail && cmd_cnt > 0) {
          if (current->character >= 'a' && current->character <= 'z' &&
              (current->next_char->character == '_' ||
               current->next_char == tail)) {
            cmd_cnt--;
            cursor = current;
          }
          current = current->next_char;
        }
      }
    } else if (mStr[i] == 'B') {
      int cmd_cnt = mStr[++i] - '0';
      auto current = cursor;

      if (current->character >= 'a' && current->character <= 'z') {
        while (current->character != '_' && current != head) {
          current = current->prev_char;
        }
      }

      if (current != head) {
        while (current != head && cmd_cnt > 0) {
          if (current->character >= 'a' && current->character <= 'z' &&
              (current->prev_char->character == '_' ||
               current->prev_char == head)) {
            cmd_cnt--;
            cursor = current;
          }
          current = current->prev_char;
        }
      }
    } else if (mStr[i] == 'D') {
      int cmd_cnt = mStr[++i] - '0';

      for (int j = 0; j < cmd_cnt; j++) {
        if (cursor == tail) {
          break;
        }
        cursor->prev_char->next_char = cursor->next_char;
        cursor->next_char->prev_char = cursor->prev_char;
        auto tmp_cursor = cursor;
        cursor = cursor->next_char;
        delete tmp_cursor;
      }
    } else {
      Character* new_character = new Character();
      new_character->character = mStr[i];
      new_character->prev_char = cursor->prev_char;
      new_character->next_char = cursor;
      cursor->prev_char->next_char = new_character;
      cursor->prev_char = new_character;
    }
    i++;
  }
  return cursor->character;
}

char getWord(int mX) {
  auto tmp_character = head->next_char;
  while (tmp_character != tail && mX > 0) {
    if (tmp_character->character >= 'a' && tmp_character->character <= 'z' &&
        (tmp_character->prev_char == head ||
         tmp_character->prev_char->character == '_'))
      mX--;
    if (mX == 0) break;
    tmp_character = tmp_character->next_char;
  }
  return tmp_character->character;
}