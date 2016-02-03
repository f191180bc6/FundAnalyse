#include "downloader.h"
#include "onedayprice.h"
#include <vector>
#include <memory>
#include <QtCore/QUrl>
#include "global.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QByteArray>
#include <QtCore/QString>
#include <QtCore/QTextCodec>
#include <QtCore/QRegExp>

using namespace std;

Downloader::Downloader()
	: nam(getNetworkAccessManager())
	, currentReply(0)
	, iCountPerPage(0)
{
	connect(nam, SIGNAL(finished(QNetworkReply *)),
			this, SLOT(onnetworkAccessManager_finished(QNetworkReply *)));

}


void Downloader::Download(int id, int per)
{
	iCountPerPage = per;
	QString str = QString("http://fund.eastmoney.com/f10/F10DataApi.aspx?type=lsjz&code=%1&page=1&per=%2").arg(id).arg(iCountPerPage);
	QUrl url(str);
	currentReply = nam->get(QNetworkRequest(url));
}

void Downloader::onnetworkAccessManager_finished(QNetworkReply *reply)
{
	if (reply != currentReply)
		return ;
	currentReply = 0;
	reply->deleteLater();

	QByteArray inputByteArray = reply->readAll();
	QString inputString(QTextCodec::codecForHtml(inputByteArray)->toUnicode(inputByteArray));



	int iPosition = 0;
	std::shared_ptr<std::vector<ONEDAYPRICE> > pvec(new std::vector<ONEDAYPRICE>);
	std::vector<ONEDAYPRICE> &vec = *pvec;
	vec.reserve(iCountPerPage);

	for (;;)
	{

// <td>2015-03-27</td>
// (\d{4})-(\d{2})-(\d{2})
// (\\d{4})-(\\d{2})-(\\d{2})

		ONEDAYPRICE price;

		QRegExp regexpDate("(\\d{4})-(\\d{2})-(\\d{2})");
		iPosition = inputString.indexOf(regexpDate, iPosition);

		if (iPosition < 0)
			break;

		price.date.setDate(regexpDate.cap(1).toInt(),
						   regexpDate.cap(2).toInt(),
						   regexpDate.cap(3).toInt());


// <td class='tor bold'>1.0830</td>
// (\d*\.\d*)
// (\\d*\\.\\d*)

		QRegExp regexpPrice("(\\d*\\.\\d*)");
		iPosition = inputString.indexOf(regexpPrice, iPosition);

		if (iPosition < 0)
			break;

		price.dPrice = regexpPrice.cap(1).toDouble();


		vec.push_back(price);

	}

	emit finish(pvec);
}
