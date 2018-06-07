using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calendar_CSharp
{
    public partial class Form1 : Form
    {
        Object calendar;
        Type type;
        short day = 0;
        short month = 0;
        short year = 0;

        public Form1()
        {
            InitializeComponent();

            type = TypeDelegator.GetTypeFromProgID("MSCAL.Календарь.7");
            calendar = Activator.CreateInstance(type);

            day = (short)type.InvokeMember("Day", BindingFlags.GetProperty, null, calendar, null);
            month = (short)type.InvokeMember("Month", BindingFlags.GetProperty, null, calendar, null);
            year = (short)type.InvokeMember("Year", BindingFlags.GetProperty, null, calendar, null);

            day_txt.Text = day.ToString();
            month_txt.Text = month.ToString();
        }

        private void get_tb_Click(object sender, EventArgs e)
        {
            day = (short)type.InvokeMember("Day", BindingFlags.GetProperty, null, calendar, null);
            month = (short)type.InvokeMember("Month", BindingFlags.GetProperty, null, calendar, null);
            year = (short)type.InvokeMember("Year", BindingFlags.GetProperty, null, calendar, null);

            MessageBox.Show("Текущая установленная дата: "+day.ToString()+"."+month.ToString()+"."+year.ToString());
        }

        private void set_tb_Click(object sender, EventArgs e)
        {
            type.InvokeMember("Day", BindingFlags.SetProperty,null,calendar, new object[] { Convert.ToUInt16(day_txt.Text) }, null, null, null);
            type.InvokeMember("Month", BindingFlags.SetProperty, null, calendar, new object[] { Convert.ToUInt16(month_txt.Text) }, null, null, null);
        }
    }
}
