#ifndef DECKVIEW_H
#define DECKVIEW_H

#include <QPixmap>

#include <QObject>

class DeckView: public QObject {
    Q_OBJECT

public:
    DeckView(QRect window);
    virtual void refresh() = 0;

    QRect getRect();

signals:
    void refreshKey(int index, QPixmap key);

private:
    QRect _window;
};

#endif // DECKVIEW_H
