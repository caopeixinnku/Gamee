#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>

class handler : public QObject
{
    Q_OBJECT
public:
    static handler* getInstance();
    void addscore();
private:
    explicit handler(QObject *parent = nullptr);

signals:
void eatfoodorai();
public slots:

private:
    static handler*hand;
};

#endif // HANDLER_H
