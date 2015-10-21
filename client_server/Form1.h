#pragma once

namespace client_server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Text;
	using namespace System::Net::Sockets;
	using namespace System::Net;
	using namespace System::IO;

	delegate void tbChangeDelegate(TextBox^ tb, String^ str);

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  b_clientStart;
	protected: 

	protected: 

	protected: 

					 TcpClient^ client;
					 TcpListener^ listner;
					 StreamReader^ sr;
					 int mainPort;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  b_clientSend;

	private: System::Windows::Forms::Label^  l_clientStatus;



	private: 


					 System::Threading::Thread^ servThread;
					 tbChangeDelegate^ tbChangeD;
	private: System::Windows::Forms::Panel^  panel1;
	public: System::Windows::Forms::Label^  l_servStatus;
	private: 
	private: System::Windows::Forms::TextBox^  textBox2;
	public: 
	private: System::Windows::Forms::Button^  b_servStart;
	private: System::Windows::Forms::Panel^  panel2;


	private: 

	public: 


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->b_clientStart = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->b_clientSend = (gcnew System::Windows::Forms::Button());
			this->l_clientStatus = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->l_servStatus = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->b_servStart = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// b_clientStart
			// 
			this->b_clientStart->Dock = System::Windows::Forms::DockStyle::Top;
			this->b_clientStart->Location = System::Drawing::Point(0, 14);
			this->b_clientStart->Name = L"b_clientStart";
			this->b_clientStart->Size = System::Drawing::Size(228, 23);
			this->b_clientStart->TabIndex = 0;
			this->b_clientStart->Text = L"go client";
			this->b_clientStart->UseVisualStyleBackColor = true;
			this->b_clientStart->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->textBox1->Location = System::Drawing::Point(0, 66);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(228, 163);
			this->textBox1->TabIndex = 1;
			// 
			// b_clientSend
			// 
			this->b_clientSend->Dock = System::Windows::Forms::DockStyle::Top;
			this->b_clientSend->Location = System::Drawing::Point(0, 37);
			this->b_clientSend->Name = L"b_clientSend";
			this->b_clientSend->Size = System::Drawing::Size(228, 23);
			this->b_clientSend->TabIndex = 0;
			this->b_clientSend->Text = L"send client";
			this->b_clientSend->UseVisualStyleBackColor = true;
			this->b_clientSend->Visible = false;
			this->b_clientSend->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// l_clientStatus
			// 
			this->l_clientStatus->AutoSize = true;
			this->l_clientStatus->BackColor = System::Drawing::Color::Chartreuse;
			this->l_clientStatus->Dock = System::Windows::Forms::DockStyle::Top;
			this->l_clientStatus->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->l_clientStatus->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->l_clientStatus->Location = System::Drawing::Point(0, 0);
			this->l_clientStatus->Name = L"l_clientStatus";
			this->l_clientStatus->Size = System::Drawing::Size(115, 14);
			this->l_clientStatus->TabIndex = 4;
			this->l_clientStatus->Text = L" Клиент запущен";
			this->l_clientStatus->Visible = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->l_servStatus);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->b_servStart);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(213, 229);
			this->panel1->TabIndex = 3;
			// 
			// l_servStatus
			// 
			this->l_servStatus->AutoSize = true;
			this->l_servStatus->BackColor = System::Drawing::Color::Chartreuse;
			this->l_servStatus->Dock = System::Windows::Forms::DockStyle::Top;
			this->l_servStatus->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->l_servStatus->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->l_servStatus->Location = System::Drawing::Point(0, 23);
			this->l_servStatus->Name = L"l_servStatus";
			this->l_servStatus->Size = System::Drawing::Size(111, 14);
			this->l_servStatus->TabIndex = 8;
			this->l_servStatus->Text = L"Сервер запущен";
			this->l_servStatus->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->textBox2->Location = System::Drawing::Point(0, 40);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(213, 189);
			this->textBox2->TabIndex = 10;
			// 
			// b_servStart
			// 
			this->b_servStart->Dock = System::Windows::Forms::DockStyle::Top;
			this->b_servStart->Location = System::Drawing::Point(0, 0);
			this->b_servStart->Name = L"b_servStart";
			this->b_servStart->Size = System::Drawing::Size(213, 23);
			this->b_servStart->TabIndex = 9;
			this->b_servStart->Text = L"go server";
			this->b_servStart->UseVisualStyleBackColor = true;
			this->b_servStart->Click += gcnew System::EventHandler(this, &Form1::b_servStart_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->b_clientSend);
			this->panel2->Controls->Add(this->b_clientStart);
			this->panel2->Controls->Add(this->l_clientStatus);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel2->Location = System::Drawing::Point(219, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(228, 229);
			this->panel2->TabIndex = 4;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(447, 229);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
						 servThread = gcnew System::Threading::Thread( gcnew System::Threading::ThreadStart(this, &Form1::ThreadProc ));
						 tbChangeD = gcnew tbChangeDelegate(this, &Form1::tbChange);
						 mainPort = 12002;
					 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
						 client = gcnew TcpClient();
						 try{
							 client->Connect(gcnew IPEndPoint(IPAddress::Parse("127.0.0.1"), mainPort));
							 this->b_clientSend->Visible=true;
							 this->l_clientStatus->Visible = true;
						 } catch (Exception^ ex)
						 {
							 MessageBox::Show("Connection error. Server unavailable :'(");
						 }

						 StreamWriter^ sw = gcnew StreamWriter(client->GetStream());
						 sw->AutoFlush = true;
						 try
						 {
							 sw->WriteLine(L"HELO");
						 }
						 catch (Exception^ ex)
						 {
							 MessageBox::Show("Send error");
						 }

						 /*client->Close();*/
					 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
						 StreamWriter^ sw = gcnew StreamWriter(client->GetStream());
						 sw->AutoFlush = true;
						 try
						 {
								 sw->WriteLine(L"GET?"+textBox1->Text);
						 }
						 catch (Exception^ ex)
						 {
							 MessageBox::Show("Send error");
						 }
					 }

					 void handshake(TcpClient^ _client) {
						 String^ token = Convert::ToString((gcnew Random)->Next(100000, 999999));
						 String^ port = Convert::ToString((gcnew Random)->Next(mainPort, mainPort + 1000));
						 File::WriteAllText(token+".tkn", port);
						 String^ msg = L"SET TOKEN " + token + L"\1 SET PORT " + port + "\1";

						 _client->GetStream()->Write();
					 }

					  void ThreadProc() { 
							if(!servThread->IsAlive)
								return;
							listner = gcnew TcpListener(gcnew IPEndPoint(IPAddress::Parse("127.0.0.1"), mainPort));
							listner->Start();
							TcpClient^ client = listner->AcceptTcpClient();
							sr = gcnew StreamReader(client->GetStream());
						 try
						 {
							 while (servThread->IsAlive)
							 {
								 String^ msg = sr->ReadLine();
								 this->Invoke(tbChangeD, gcnew array<Object^> {textBox2, msg+Environment::NewLine});
								 if (msg->IndexOf(L"HELO", 0) != -1 ) {
									 handshake(client);
								 }
								 int queryIndx=msg->IndexOf(L"GET", 0);
								 if( queryIndx == -1) {
		 								// MessageBox::Show(msg);
								 } else {
									 queryIndx=msg->IndexOf(L"?", queryIndx);
									 String^ query=msg->Substring(queryIndx+1);
									 array<String^>^ params = query->Split(L'&');
									 for (int i=0; i<params->Length; i++)
									 {
										 int equalIndx = params[i]->IndexOf(L"=");
										 if(equalIndx != -1) {
											 String^ param = (params[i]->Split(' '))[0];
											 String^ key = param->Split('=')[0];
											 String^ val = param->Split('=')[1];
											 MessageBox::Show(L"Action = "+key+L" \r\nValue = "+val);
										 } else 
											 this->Invoke(tbChangeD, gcnew array<Object^> {textBox2, params[i]});
									 }
								 }
// 								 msg->Substring()

							 }
						 }
						 catch (Exception^ ex)
						 {
							 MessageBox::Show(L"Соединение разорвано!");
// 							 this->b_clientSend->Visible = false;
// 							 this->l_clientStatus->Visible = false;
						   listner->Stop();
							 client->Close();
							 sr->Close();
							ThreadProc();
						 }
 						 listner->Stop();
						 client->Close();
						 sr->Close();

					 };

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {;
				 }
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
					 servThread->Abort();
					 try
					 {
					 StreamWriter^ sw = gcnew StreamWriter(client->GetStream());
					 sw->AutoFlush = true;
						 sw->WriteLine("");
					 }
					 catch (Exception^ ex)
					 {
						 MessageBox::Show("disconnect");
					 }

				 }

				 void tbChange(TextBox^ tb, String^ str) {
					 tb->Text+=str;//+Environment::NewLine;
				 };


private: System::Void b_servStart_Click(System::Object^  sender, System::EventArgs^  e) {
					 if(servThread->IsAlive) {
						 l_servStatus->Visible=true;
						 l_servStatus->Text=L"Сервер останавливается";
						 servThread->Abort(1);
					 } else {
						 servThread->Start();
						 l_servStatus->Visible=true;
						 l_servStatus->Text=L"Сервер запущен";
					 }

				 }
};
}

