#include "MainWdg.h"
#include <QWebEngineView>
#include <QWebEngineSettings>
CMainWdg::CMainWdg(QWidget* parent) :QWidget(parent)
{
	setFixedSize(400, 300);
	setWindowIcon(QIcon(":/res/mr.png"));
	setWindowTitle(QString::fromWCharArray(L"Music Radio"));
	m_mainVBL = new QVBoxLayout(this);

	QWebEngineView* LiveView = new QWebEngineView;
	LiveView->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
	LiveView->setAttribute(Qt::WA_DeleteOnClose);
	LiveView->load(QUrl("https://lhttp.qingting.fm/live/388/64k.mp3?app_id=web"));
	m_mainVBL->addWidget(LiveView);
	m_mainVBL->addStretch();

	QMenu* pMenu = new QMenu;
	QAction*  actQuit = pMenu->addAction(QString::fromWCharArray(L"ÍË³ö"));

	m_systemTray = new QSystemTrayIcon(this);
	m_systemTray->setContextMenu(pMenu);
	m_systemTray->setIcon(QIcon(":/res/mr.png"));
	m_systemTray->setToolTip("Music Radio");
	m_systemTray->show();
	
	//ÍË³ö
	connect(actQuit, SIGNAL(triggered(bool)), QCoreApplication::instance(), SLOT(quit()));
	//µ¥»÷ÍÐÅÌÍ¼±ê
	connect(m_systemTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onActivated(QSystemTrayIcon::ActivationReason)));
	//connect(LiveView, SIGNAL(urlChanged(const QUrl&)), this, SLOT(onUrlChanged(const QUrl&)));
}

void CMainWdg::onActivated(QSystemTrayIcon::ActivationReason reason)
{
	if (reason == QSystemTrayIcon::Trigger)
	{
		//isVisible() ? hide() : showNormal();
		if (!isVisible())
		{
			//ÉèÖÃ´°¿ÚÖÃ¶¥
			//::SetWindowPos(HWND(this->winId()), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
			//::SetWindowPos(HWND(this->winId()), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

			showNormal();
			activateWindow();
		}
		else
		{
			hide();
		}
	}
}
