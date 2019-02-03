// C++ implementation to read
// file word by word
#include <bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

class wordGame
{
public:
  string word;
  bool found = false;
  int score = 0;
  char lastLetter,firstLetter,checkLetter;
  void inputWord();
  void checkDisc();
  void checkLastLetter();
  void random();
};

void wordGame :: random(){
    int r;
    srand (time(NULL));   
    r = rand() % 26;   
    checkLetter = 'a' + r;     
}

void wordGame :: inputWord(){
  cout << "Enter your next word starting with : "<<lastLetter<<"\n";
  cin >> word;
  firstLetter = word.at(0);
  checkDisc();
}

void wordGame :: checkLastLetter(){
  if(firstLetter == checkLetter){
      
      score++;
      checkLetter = lastLetter;
      inputWord();
  }
  else
  {
    cout<<"game over!\n Your score is : "<<score;
  }
}

void wordGame :: checkDisc(){
  fstream file;
    string str,filename;
    filename = "file.txt";
    file.open(filename.c_str());
    while (file >> str)
    {   found = false;
        if(word == str){
          found = true;
          int len = word.length();
          lastLetter = word.at(len-1);
          checkLastLetter();
          break;
        }
    } 
}

int main(){
  wordGame obj;
  obj.random();
  cout<<"Enter your first word starting with : "<<obj.checkLetter<<"\n";
  cin>>obj.word;
  obj.firstLetter = obj.checkLetter;
  obj.checkDisc();
  if(obj.found == false){
    cout<<"Game over!\n"<<"Your score is : "<<obj.score;
  }
  return 0;
}