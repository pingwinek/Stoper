#pragma once

namespace Stoper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		int seconds = 0;
		int minutes = 0;
		int setne = 0;
		int startstop = 1;
		int sprawdzenie = 20;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(34, 199);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"START/STOP";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(164, 199);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"RESET";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(36, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(191, 37);
			this->label1->TabIndex = 3;
			this->label1->Text = L"00 : 00 : 00";
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(268, 244);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Stoper";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	startstop *= -1;
	if (startstop == -1) timer1->Start();
	else timer1->Stop();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	timer1->Stop();
	setne = 0;
	seconds = 0;
	minutes = 0;
	label1->Text = "00 : 00 : 00";
	startstop = 1;
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	setne++;
	if (setne == 100)
	{
		setne = 0;
		seconds++;
	}
	if (seconds == 60)
	{
		seconds = 0;
		minutes++;
	}

	if (minutes <= 9)
	{
		if (seconds <= 9)
		{
			if (setne <= 9)
			{
				label1->Text = "0" + minutes + " : 0" + seconds + " : 0" + setne;
			}
			else
			{
				label1->Text = "0" + minutes + " : 0" + seconds + " : " + setne;
			}
		}
		else
		{
			if (setne <= 9)
			{
				label1->Text = "0" + minutes + " : " + seconds + " : 0" + setne;
			}
			else
			{
				label1->Text = "0" + minutes + " : " + seconds + " : " + setne;
			}
		}
	}
	else
	{
		if (seconds <= 9)
		{
			if (setne <= 9)
			{
				label1->Text = minutes + " : 0" + seconds + " : 0" + setne;
			}
			else
			{
				label1->Text = minutes + " : 0" + seconds + " : " + setne;
			}
		}
		else
		{
			if (setne <= 9)
			{
				label1->Text = minutes + " : " + seconds + " : 0" + setne;
			}
			else
			{
				label1->Text = minutes + " : " + seconds + " : " + setne;
			}
		}
	}
}
};
}
