#include <QtGui>
#include "mainwindow.h"
#include <cmath>

int bitsCount = 8;

MainWindow::MainWindow() {
	setWindowTitle(tr("Bits"));
	setFixedSize(420, 220);
	
	rectW = 50;
	rectH = 50;
	rectStartW = 10;
	rectStartH = 50;

    for(int i = 0; i < bitsCount; i++) {
    	bitLabel[i] = new QLabel(this);
		bitLabel[i]->setGeometry(rectStartW + rectW * i, rectStartH - 20, rectW, 20);
		bitLabel[i]->setFont(QFont("Courier", 20, QFont::Bold));
		bitLabel[i]->setText( "0" );

		bit[i] = 0;
    }

    binLabel = new QLabel(this);
	binLabel->setGeometry(10, 110, 400, 20);
	binLabel->setFont(QFont("Courier", 20, QFont::Bold));
	binLabel->setText( "Bin: " );

	hexLabel = new QLabel(this);
	hexLabel->setGeometry(10, 140, 400, 20);
	hexLabel->setFont(QFont("Courier", 20, QFont::Bold));
	hexLabel->setText( "Hex: " );

	decLabel = new QLabel(this);
	decLabel->setGeometry(10, 170, 400, 20);
	decLabel->setFont(QFont("Courier", 20, QFont::Bold));
	decLabel->setText( "Dec: ");

}

void MainWindow::paintEvent( QPaintEvent * ) {
	QPainter p(this);
	p.setPen(QPen(Qt::black));

	for(int i = 0; i < bitsCount; i++) {
    	(bit[i] == 0) ? p.setBrush(QBrush(Qt::black)) : p.setBrush(QBrush(Qt::white));
    	p.drawRect(rectStartW + rectW * i, rectStartH, rectW, rectH);
    	bitLabel[i]->setText(QString::number(bit[i]));
    	binLabel->setText( "Bin: " + QString::number(bitsToDec(), 2) );
    	decLabel->setText( "Dec: " + QString::number(bitsToDec()));
    	hexLabel->setText( "Hex: " + QString::number(bitsToDec(), 16));
    }
}

int MainWindow::bitsToDec() {
	int res = 0;
	for(int i = bitsCount - 1; i >= 0; i--) {
		res += pow(2, (bitsCount - (i + 1))) * bit[i];
	}
	return res;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
	int x = event->x();
	int y = event->y();

	for(int i = 0; i < bitsCount; i++) {
		if( x > rectStartW + rectW * i && x < rectStartW + rectW * i + rectW && y > rectStartH && y < rectStartH + rectH ) {
			bit[i] = !bit[i];
		}
	}
	update();
}