#ifndef UI
#define UI

#include"Buyers.h"

namespace Liuyuan
{
	//UI: not logined
	void UI_basic();

	//UI: login
	void UI_login();

	//UI: logined
	void UI_logined();

	//UI: super user
	void UI_logined_superUsr();

	//UI: super user set guest
	void UI_logined_superUsr_setGuest();

	//UI: super user change guest kind
	void UI_logined_superUsr_changeKind();

	//UI: super user change layfork
	void UI_logined_superUsr_changeLayfork(Layfork* ptr);

	//UI: super user change number
	void UI_logined_superUsr_changeNumber(Number* ptr);

	//UI: super user change honoured
	void UI_logined_superUsr_changeHonoured(Honoured_guest* ptr);

	//UI: super user set books
	void UI_logined_superUsr_setBooks();

	//UI: purchase book
	void UI_buyBook();

	//UI: print book information
	void UI_printBook();
}

#endif
