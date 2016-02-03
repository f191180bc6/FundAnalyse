#include "global.h"
#include <QtNetwork/QNetworkAccessManager>

QNetworkAccessManager *getNetworkAccessManager()
{
	static QNetworkAccessManager networkAccessManager;
	return &networkAccessManager;
}
