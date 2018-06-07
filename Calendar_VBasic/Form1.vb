
Public Class Form1

    Dim calendar = CreateObject("MSCAL.Календарь.7")

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        calendar = CreateObject("MSCAL.Календарь.7")
        day_txt.Text = calendar.Day
        month_txt.Text = calendar.Month
    End Sub

    Private Sub get_tb_Click(sender As Object, e As EventArgs) Handles get_tb.Click

        MsgBox("Текущая установленная дата: " + calendar.Day.ToString() + "." + calendar.Month.ToString() + "." + calendar.Year.ToString())
    End Sub

    Private Sub set_bt_Click(sender As Object, e As EventArgs) Handles set_bt.Click
        calendar.Day = CShort(day_txt.Text)
        calendar.Month = CShort(month_txt.Text)

    End Sub
End Class
