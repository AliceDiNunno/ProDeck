#ifndef DECKVIEW_H
#define DECKVIEW_H

#include <QPixmap>

#include <QObject>

class DeckView: public QObject {
    Q_OBJECT
public:
    virtual void refresh() = 0;

signals:
    void refreshKey(int index, QPixmap key);
};

#endif // DECKVIEW_H
