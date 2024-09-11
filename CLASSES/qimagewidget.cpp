#include "qimagewidget.h"
#include<QMouseEvent>
#include<QPainter>
#include<QFileDialog> // for dialog window of file choosing

QImageWidget::QImageWidget(QWidget *parent)
    : QWidget{parent}
{
    this->noImageMessage = "NO IMAGE";
    this->background = Qt::blue;
    this->margin = 4;

    connect(this, SIGNAL(marginChanged()), SLOT(repaint()));
    connect(this, SIGNAL(pixmapChanged()), SLOT(repaint()));
}

QImageWidget::~QImageWidget()
{

}

void QImageWidget::setPixmap(QPixmap pixmap)
{
    this->originalImage = pixmap;
    updateMargins();
    emit pixmapChanged();
}

QRect QImageWidget::actuelImageRect()
{
    QRect imageRect = rect(); // widget area
    imageRect.setSize(this->originalImage.size().scaled(size(), Qt::KeepAspectRatio));
    // KeepAspectRatio means save side's ratio
    imageRect.moveCenter(rect().center());
    return imageRect; // area
}

void QImageWidget::updateMargins()
{
    double ratio = (double)this->originalImage.height() / this->originalImage.width();
    int hMargin = this->margin * ratio;
    int vMargin = this->margin;

    this->margins.setBottom(hMargin);
    this->margins.setTop(hMargin);
    this->margins.setLeft(vMargin);
    this->margins.setRight(vMargin);
}

void QImageWidget::setMargine(int value)
{
    if(value < 2)
        value = 2;
    if(value > 40)
        value = 40;
    if(value != this->margin){
        this->margin = value;
        updateMargins();
        emit marginChanged();
    }
}

void QImageWidget::mouseDoubleClickEvent(QMouseEvent *event){
    if(event->button() != Qt::LeftButton)
        return;
    else{
        QString filename = QFileDialog::getOpenFileName(this);
        if(filename.isEmpty())
            return;
        else{
            setPixmap(QPixmap(filename));
        }
    }
}

void QImageWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    // in construct we have to point at device ~which~ we will to paint
    painter.setRenderHint(QPainter::Antialiasing); // ~smoothing~
    painter.save(); // here saves seted hints, and would we add new painter,
        // we can call .restore() to set these hints
    painter.setBrush(this->background);
    painter.drawRect(rect());

    painter.restore();
    if(originalImage.isNull()){
        painter.drawText(rect(), Qt::AlignCenter, this->noImageMessage);
    }
    else{
        QRect imageRect = actuelImageRect(); // rect() returns all widget's area
        painter.drawPixmap(imageRect.marginsRemoved(this->margins), this->originalImage);
    }
}

