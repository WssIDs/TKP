namespace Calendar_CSharp
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.set_tb = new System.Windows.Forms.Button();
            this.get_tb = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.day_txt = new System.Windows.Forms.TextBox();
            this.month_txt = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // set_tb
            // 
            this.set_tb.Location = new System.Drawing.Point(19, 77);
            this.set_tb.Name = "set_tb";
            this.set_tb.Size = new System.Drawing.Size(75, 23);
            this.set_tb.TabIndex = 0;
            this.set_tb.Text = "Задать";
            this.set_tb.UseVisualStyleBackColor = true;
            this.set_tb.Click += new System.EventHandler(this.set_tb_Click);
            // 
            // get_tb
            // 
            this.get_tb.Location = new System.Drawing.Point(19, 106);
            this.get_tb.Name = "get_tb";
            this.get_tb.Size = new System.Drawing.Size(75, 23);
            this.get_tb.TabIndex = 1;
            this.get_tb.Text = "Получить";
            this.get_tb.UseVisualStyleBackColor = true;
            this.get_tb.Click += new System.EventHandler(this.get_tb_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(16, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(34, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "День";
            // 
            // day_txt
            // 
            this.day_txt.Location = new System.Drawing.Point(19, 31);
            this.day_txt.Name = "day_txt";
            this.day_txt.Size = new System.Drawing.Size(100, 20);
            this.day_txt.TabIndex = 3;
            this.day_txt.Text = "0";
            // 
            // month_txt
            // 
            this.month_txt.Location = new System.Drawing.Point(206, 31);
            this.month_txt.Name = "month_txt";
            this.month_txt.Size = new System.Drawing.Size(100, 20);
            this.month_txt.TabIndex = 5;
            this.month_txt.Text = "0";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(203, 15);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(40, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Месяц";
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(341, 142);
            this.Controls.Add(this.month_txt);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.day_txt);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.get_tb);
            this.Controls.Add(this.set_tb);
            this.Name = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button set_tb;
        private System.Windows.Forms.Button get_tb;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox day_txt;
        private System.Windows.Forms.TextBox month_txt;
        private System.Windows.Forms.Label label2;
    }
}

