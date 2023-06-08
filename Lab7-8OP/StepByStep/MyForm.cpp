#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    TryCatch::MyForm form;
    Application::Run(% form);
    return 0;
}