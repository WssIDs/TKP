using ATLPR1Lib;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace СSharpClient_LB3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int ITERATIONS = 50000000;

        private void button2_Click(object sender, EventArgs e)
        {
            DateTime Start = DateTime.Now;
            var obj = new ATLPR1Lib.MyMath();

            txtZ.Text = (obj.Add(Convert.ToDouble(txtX.Text), Convert.ToDouble(txtY.Text))).ToString();

            for (int i = 0; i < ITERATIONS; i++)
            {
                obj.Add(Convert.ToDouble(txtX.Text), Convert.ToDouble(txtY.Text));
            }

            txtTime2.Text = ((DateTime.Now - Start).TotalSeconds).ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            DateTime Start = DateTime.Now;
            var obj = new MyMathClass();

            txtZ.Text = (obj.Add(Convert.ToDouble(txtX.Text), Convert.ToDouble(txtY.Text))).ToString();

            for (int i = 0; i < ITERATIONS; i++)
            {
                obj.Add(Convert.ToDouble(txtX.Text), Convert.ToDouble(txtY.Text));
            }

            txtTime3.Text = ((DateTime.Now - Start).TotalSeconds).ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DateTime Start = DateTime.Now;
            var atlPRType = Type.GetTypeFromProgID("ATL_PR_1.MyMath.1");

            if (atlPRType != null)
            {
                var obj = Activator.CreateInstance(atlPRType);

                if(obj != null)
                {
                    IMyMath myMath = (IMyMath)obj;

                    txtZ.Text = (myMath.Add(Convert.ToDouble(txtX.Text), Convert.ToDouble(txtY.Text))).ToString();


                    for (int i = 0; i < ITERATIONS; i++)
                    {
                        myMath.Add(Convert.ToDouble(txtX.Text), Convert.ToDouble(txtY.Text));
                    }

                    txtTime1.Text = ((DateTime.Now - Start).TotalSeconds).ToString();
                }
            }
        }
    }
}
