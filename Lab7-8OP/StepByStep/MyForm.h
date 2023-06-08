#pragma once
#include "Header.h"

namespace TryCatch {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();

        }

    protected:

        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::Label^ labelFirstVariable1;
        System::Windows::Forms::Label^ labelFirstVariable2;
        System::Windows::Forms::Label^ labelFirstVariable3;
        System::Windows::Forms::Label^ labelSecondVariable1;
        System::Windows::Forms::Label^ labelSecondVariable2;
        System::Windows::Forms::Label^ labelSecondVariable3;
        System::Windows::Forms::TextBox^ inputFirstVariable1;
        System::Windows::Forms::TextBox^ inputFirstVariable2;
        System::Windows::Forms::TextBox^ inputFirstVariable3;
        System::Windows::Forms::TextBox^ inputSecondVariable1;
        System::Windows::Forms::TextBox^ inputSecondVariable2;
        System::Windows::Forms::TextBox^ inputSecondVariable3;
        System::Windows::Forms::TextBox^ textBoxOutput;

        System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->labelFirstVariable1 = (gcnew System::Windows::Forms::Label());
            this->labelFirstVariable2 = (gcnew System::Windows::Forms::Label());
            this->labelFirstVariable3 = (gcnew System::Windows::Forms::Label());
            this->labelSecondVariable1 = (gcnew System::Windows::Forms::Label());
            this->labelSecondVariable2 = (gcnew System::Windows::Forms::Label());
            this->labelSecondVariable3 = (gcnew System::Windows::Forms::Label());
            this->inputFirstVariable1 = (gcnew System::Windows::Forms::TextBox());
            this->inputFirstVariable2 = (gcnew System::Windows::Forms::TextBox());
            this->inputFirstVariable3 = (gcnew System::Windows::Forms::TextBox());
            this->inputSecondVariable1 = (gcnew System::Windows::Forms::TextBox());
            this->inputSecondVariable2 = (gcnew System::Windows::Forms::TextBox());
            this->inputSecondVariable3 = (gcnew System::Windows::Forms::TextBox());
            this->textBoxOutput = (gcnew System::Windows::Forms::TextBox()); 
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(50, 50);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(100, 23);
            this->button1->Text = L"Solve";
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::Solve_Click);
            // 
            // textBoxInput1
            // 
            this->inputFirstVariable1->Location = System::Drawing::Point(50, 100);
            this->inputFirstVariable1->Name = L"textBoxInput1";
            this->inputFirstVariable1->Size = System::Drawing::Size(100, 20);
            this->inputFirstVariable1->TabIndex = 0;
            // 
            // textBoxInput2
            // 
            this->inputFirstVariable2->Location = System::Drawing::Point(50, 150);
            this->inputFirstVariable2->Name = L"textBoxInput2";
            this->inputFirstVariable2->Size = System::Drawing::Size(100, 20);
            this->inputFirstVariable2->TabIndex = 0;
            // 
            // textBoxInput3
            // 
            this->inputFirstVariable3->Location = System::Drawing::Point(50, 200);
            this->inputFirstVariable3->Name = L"textBoxInput3";
            this->inputFirstVariable3->Size = System::Drawing::Size(100, 20);
            this->inputFirstVariable3->TabIndex = 0;
            // 
            // textBoxInput4
            // 
            this->inputSecondVariable1->Location = System::Drawing::Point(300, 100);
            this->inputSecondVariable1->Name = L"textBoxInput1";
            this->inputSecondVariable1->Size = System::Drawing::Size(100, 20);
            this->inputSecondVariable1->TabIndex = 0;
            // 
            // textBoxInput5
            // 
            this->inputSecondVariable2->Location = System::Drawing::Point(300, 150);
            this->inputSecondVariable2->Name = L"textBoxInput2";
            this->inputSecondVariable2->Size = System::Drawing::Size(100, 20);
            this->inputSecondVariable2->TabIndex = 0;
            // 
            // textBoxInput6
            // 
            this->inputSecondVariable3->Location = System::Drawing::Point(300, 200);
            this->inputSecondVariable3->Name = L"textBoxInput3";
            this->inputSecondVariable3->Size = System::Drawing::Size(100, 20);
            this->inputSecondVariable3->TabIndex = 0;
            // 
            // textBoxOutput
            // 
            this->textBoxOutput->Location = System::Drawing::Point(50, 250);
            this->textBoxOutput->Name = L"textBoxOutput";
            this->textBoxOutput->ReadOnly = true;
            this->textBoxOutput->Size = System::Drawing::Size(75, 20);
            this->textBoxOutput->TabIndex = 0;
            //
            // Label1
            // 
            this->labelFirstVariable1->AutoSize = true;
            this->labelFirstVariable1->Location = System::Drawing::Point(50, 80);
            this->labelFirstVariable1->Name = L"labelFirstVariable1";
            this->labelFirstVariable1->Size = System::Drawing::Size(46, 13);
            this->labelFirstVariable1->Text = L"Variable1";
            // 
            // labelFirstVariable2
            // 
            this->labelFirstVariable2->AutoSize = true;
            this->labelFirstVariable2->Location = System::Drawing::Point(50, 130);
            this->labelFirstVariable2->Name = L"labelFirstVariable2";
            this->labelFirstVariable2->Size = System::Drawing::Size(46, 13);
            this->labelFirstVariable2->Text = L"Variable2";
            // 
            // labelFirstVariable3
            // 
            this->labelFirstVariable3->AutoSize = true;
            this->labelFirstVariable3->Location = System::Drawing::Point(50, 180);
            this->labelFirstVariable3->Name = L"labelFirstVariable3";
            this->labelFirstVariable3->Size = System::Drawing::Size(46, 13);
            this->labelFirstVariable3->Text = L"Variable3";
            // 
            // labelSecondVariable1
            // 
            this->labelSecondVariable1->AutoSize = true;
            this->labelSecondVariable1->Location = System::Drawing::Point(300, 80);
            this->labelSecondVariable1->Name = L"labelSecondVariable1";
            this->labelSecondVariable1->Size = System::Drawing::Size(46, 13);
            this->labelSecondVariable1->Text = L"Variable1";
            // 
            // labelSecondVariable2
            // 
            this->labelSecondVariable2->AutoSize = true;
            this->labelSecondVariable2->Location = System::Drawing::Point(300, 130);
            this->labelSecondVariable2->Name = L"labelSecondVariable2";
            this->labelSecondVariable2->Size = System::Drawing::Size(46, 13);
            this->labelSecondVariable2->Text = L"Variable2";
            // 
            // labelSecondVariable3
            // 
            this->labelSecondVariable3->AutoSize = true;
            this->labelSecondVariable3->Location = System::Drawing::Point(300, 180);
            this->labelSecondVariable3->Name = L"labelSecondVariable3";
            this->labelSecondVariable3->Size = System::Drawing::Size(46, 13);
            this->labelSecondVariable3->Text = L"Variable3";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(500, 400);
            this->Controls->Add(this->button1);
            this->Controls->Add(labelFirstVariable1);
            this->Controls->Add(labelFirstVariable2);
            this->Controls->Add(labelFirstVariable3);
            this->Controls->Add(labelSecondVariable1);
            this->Controls->Add(labelSecondVariable2);
            this->Controls->Add(labelSecondVariable3);
            this->Controls->Add(this->inputFirstVariable1);
            
            this->Controls->Add(this->inputFirstVariable2);
            this->Controls->Add(this->inputFirstVariable3);
            this->Controls->Add(this->inputSecondVariable1);
            this->Controls->Add(this->inputSecondVariable2);
            this->Controls->Add(this->inputSecondVariable3);
            this->Controls->Add(this->textBoxOutput);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }


#pragma endregion
    private:
        

        System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        }

        System::Void Solve_Click(System::Object^ sender, System::EventArgs^ e) {
            try
            {
                String^ variableFirst1 = inputFirstVariable1->Text; 
                String^ variableFirst2 = inputFirstVariable2->Text;
                String^ variableFirst3 = inputFirstVariable3->Text;

                String^ variableSecond1 = inputSecondVariable1->Text;
                String^ variableSecond2 = inputSecondVariable2->Text;
                String^ variableSecond3 = inputSecondVariable3->Text;
                double coefA_first = Double::Parse(variableFirst1);
                double coefB_first = Double::Parse(variableFirst2);
                double coefC_first = Double::Parse(variableFirst3);
                double coefA_second = Double::Parse(variableSecond1);
                double coefB_second = Double::Parse(variableSecond2);
                double coefC_second = Double::Parse(variableSecond3);
                QuadraticEquation firstequation(coefA_first, coefB_first, coefC_first);
                QuadraticEquation secondequation(coefA_second, coefB_second, coefC_second);
                double solve_first = firstequation.Solve();
                double solve_second = secondequation.Solve();
                double solve = solve_first + solve_second / 2 ;

                textBoxOutput->Text = solve.ToString();
            }
            catch (System::FormatException^ ex) {
                textBoxOutput->Text = "Ошибка формата";
            }
            catch (System::OverflowException^ ex) {
                textBoxOutput->Text = "Ошибка переполнения";
            }
            catch (const MyException& ex) {

                textBoxOutput->Text = gcnew System::String(ex.GetMessage());
            }
            
        }

    };
}
