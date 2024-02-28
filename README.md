# HANGMAN GAME

## A fully functional Hangman Game, that has been designed just using C++.

This project was designed as a fun game and as a project for Computer Graphics subject during my 3rd semester journey at Texas Internal College, Kathmandu-Nepal. The highlighting features of this game are:

- You can play this game as a Learning place for English words.
- You can make your children play this game, as this will/may help them to learn something new.
- Take a detour at this fun yet a simple game using C++ graphics programming.

```c++
#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
    int gd=DETECT, gm;
    initgraph(&gm,&gd,"");
    setcolor(CYAN);
    cleardevice();
    outtextxy(200,200,"Welcome to Hangman game");
    getch();
    closegraph();
    return 0;
}
```

## In-game images

<img src="https://github.com/darkkpheonyx/Hangman-Game/blob/master/Images/Loading%20page.png" alt="loading imgae" height=300 width=300> 

<img src="https://github.com/darkkpheonyx/Hangman-Game/blob/master/Images/Ingame.png" alt="playing game image" height=300 width=300>  

<img src="https://github.com/darkkpheonyx/Hangman-Game/blob/master/Images/result.png" alt="result image" height=300 width=300>

## Authors

- [@darkkpheonyx](https://github.com/darkkpheonyx)

## Documentation

[Check out the Documentation here.](https://docs.google.com/document/d/1rvDTdmEmU53e5OW6EzRvbgsiDeGL_p43/edit?usp=drive_link&ouid=107100321595771104912&rtpof=true&sd=true)  
[Download the documentation here.](https://drive.usercontent.google.com/download?id=1rvDTdmEmU53e5OW6EzRvbgsiDeGL_p43&export=download&authuser=0&confirm=t&uuid=bc9f8802-0e56-47e0-9566-329cc9569e25&at=APZUnTWfzmigGL-Yksu_hQjGemRj:1709123909495)

## Installation

- [Clone this repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository) or [download the repository](https://github.com/darkkpheonyx/Hangman-Game/archive/refs/heads/master.zip) and unzip the contents.

* Then enjoy the game.

## Current hurdles

Currently, this project has some issues:

- The game takes inputs despite of just being in the loading screen.
- It skips certain Entered letters while compairing it to the database(i.e. Words in the DB).
- The game doesn't have a proper menu and the Read Instructions of how to play this game is not prepared yet.  
  <br>Despite of all these issues, you will definately enjoy this game.

## Get Involved

Want to show support? You can star the github repository.  
Have any questions? [Start a new discussion](https://github.com/darkkpheonyx/Hangman-Game/discussions)  
Find a bug or have any suggestions? [Open an issues](https://github.com/darkkpheonyx/Hangman-Game/issues/new)  
Want to contribute[Look for open issues you can help with](https://github.com/darkkpheonyx/Hangman-Game/issues)

## Feedback

If you have any feedback, please reach out to us at deepgeneral33@gmail.com
