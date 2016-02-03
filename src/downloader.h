#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include "onedayprice.h"
#include <vector>
#include <memory>
#include <QtCore/QUrl>

class QNetworkAccessManager;
class QNetworkReply;

class Downloader : public QObject
{
	Q_OBJECT;

public:
	Downloader();
	void Download(int id, int per); // 基金id号，per获取多少项

signals:
	void finish(std::shared_ptr<std::vector<ONEDAYPRICE> > pvec);








private slots:
	void onnetworkAccessManager_finished(QNetworkReply *reply);

private:
	QNetworkAccessManager *nam;
	QNetworkReply *currentReply;
	int iCountPerPage;
};

#endif
