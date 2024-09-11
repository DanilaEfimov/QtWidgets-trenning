#ifndef QIMAGEWIDGET_H
#define QIMAGEWIDGET_H

#include <QWidget>
#include<QPixmap>
#include<QMargins>
#include<QPainter>

class QImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QImageWidget(QWidget *parent = nullptr);
    ~QImageWidget();

    void setPixmap(QPixmap pixmap);
    QPixmap pixmap();

    int _margin() { return margin;}

private:
    QPixmap originalImage;
    QString noImageMessage;
    QMargins margins;
    int margin;
    QColor background;

    QRect actuelImageRect();
    void updateMargins();

signals:
    void pixmapChanged();
    void marginChanged();
public slots:
    void setMargine(int value);

    // QWidget interface
protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *);
};

#endif // QIMAGEWIDGET_H
