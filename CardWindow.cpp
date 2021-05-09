#include "CardWindow.h"
#include "ui_cardwindow.h"

CardWindow::CardWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardWindow)
{
    ui->setupUi(this);
}
CardWindow::CardWindow(unsigned int cardId, QLabel* DeckDisplay, DeckBuilder* deck ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardWindow),
    cardId_(cardId),
    DeckDisplay_(DeckDisplay),
    deck_(deck)
{
    ui->setupUi(this);
    QPixmap picture("../../BakcylProgramowania_2020/source/pic.png");
    int wp = ui->label->width();
    int hp = ui->label->height();
    ui->label->setPixmap(picture.scaled(wp,hp,Qt::KeepAspectRatio));
    this->setWindowTitle("Card");
    displayDeck();

}
CardWindow::~CardWindow()
{
    delete ui;
}

void CardWindow::on_close_w_clicked()
{
    close();
}

void CardWindow::on_add_w_clicked()
{

}

void CardWindow::displayDeck(){
    for(auto it : (deck_->getDeck()).getCardsAsVector()){
        deckText_ += it.name;
        deckText_ += '\n';
    }
    DeckDisplay_->setText(QString::fromStdString(deckText_));
}
