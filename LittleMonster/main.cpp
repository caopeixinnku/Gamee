#include "mainwindow.h"
#include"dialog.h"
#include"dialog_first.h"
#include"dialog_help.h"
#include"dialog_gameover.h"
#include"dialog_pause.h"
#include"dialog_victory.h"
#include"myscenen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Dialog choose;
    Dialog_first fir;
    Dialog_help help;
    dialog_gameover gameover;
    Dialog_pause pause;
    Dialog_victory victory;

    //f.show();

    fir.show();
   // gameover.show();
    //信号们与槽们的交互
    QObject::connect(&fir,SIGNAL(showchoose()),&choose,SLOT(get_first_signal()));//开始到选关的
    QObject::connect(&choose,SIGNAL(backtofirst()),&fir,SLOT(receivesignal()));//选关回开始的
    QObject::connect(&fir,SIGNAL(showhelper()),&help,SLOT(turntohelper()));//开始到帮助的
    QObject::connect(&help,SIGNAL(turnbacktofir()),&fir,SLOT( receivehelpsignal()));//帮助回开始的
    QObject::connect(&choose,SIGNAL(firscene()),&w,SLOT(catch_choose_signal()));//选关到第一关的
    QObject::connect(&gameover,SIGNAL(returntochoose()),&choose,SLOT(receivegameover()));//GAMEOVER到选关的
    QObject::connect(&gameover,SIGNAL(returntomain()),&w,SLOT(catch_gameover_signal()));//重新开始游戏的
    QObject::connect(&w,SIGNAL(sendpause()),&pause,SLOT(reveivethepause()));//开始暂停界面
    QObject::connect(&pause,SIGNAL(returntothechoose()),&choose,SLOT(get_pause_signal()));//从暂停到选关
    QObject::connect(&pause,SIGNAL(returntothemain()),&w,SLOT(catch_pause_signal()));

    QObject::connect(w.getsc(),SIGNAL(signal_victory()),&victory,SLOT(receive_victory()));
    QObject::connect(w.getsc(),SIGNAL(signal_defeat()),&gameover,SLOT(receive_gameover()));


    return a.exec();
}
