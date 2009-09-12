// lazyslash.cpp : main project file.

#include "stdafx.h"
#include "compowindow.h"

using namespace lazyslash;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew CompoWindow());
	return 0;
}
