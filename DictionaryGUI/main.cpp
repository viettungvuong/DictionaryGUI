#include "main.h"
#include "functions.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	DictionaryGUI::main frm;
	Application::Run(% frm);
}

