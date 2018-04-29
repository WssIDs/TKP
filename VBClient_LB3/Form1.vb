Public Class Form1
    Const ITERATIONS = 50000000
    Private Sub BT_Late_Click(ByVal sender As Object, ByVal e As EventArgs) Handles BT_Late.Click
        ' Пример позднего связывания
        Dim obj As Object
        Dim i As Long
        Dim Start As DateTime = DateTime.Now
        ' Создание объекта с указанным ProgId
        obj = CreateObject("ATL_PR_1.MyMath.1")
        txtZ.Text = obj.Add(txtX.Text, txtY.Text)
        For i = 1 To ITERATIONS
            obj.Add(txtX.Text, txtY.Text)
        Next
        txtTime1.Text = (DateTime.Now - Start).TotalSeconds
        obj = Nothing
    End Sub

    Private Sub BT_ID_Click(ByVal sender As Object, ByVal e As EventArgs) Handles BT_ID.Click
        ' Пример ID-связывания          
        Dim obj As ATLPR1Lib.MyMath
        'указание на TypeLib
        Dim i As Long
        Dim Start As DateTime = DateTime.Now
        obj = New ATLPR1Lib.MyMath
        txtZ.Text = obj.Add(txtX.Text, txtY.Text)
        For i = 1 To ITERATIONS
            obj.Add(txtX.Text, txtY.Text)
        Next
        txtTime2.Text = (DateTime.Now - Start).TotalSeconds
    End Sub

    Private Sub BT_vtbl_Click(ByVal sender As Object, ByVal e As EventArgs) Handles BT_vtbl.Click
        ' Пример связывания через vtbl(очень раннего связывания)
        Dim i As Long
        Dim obj As New ATLPR1Lib.MyMathClass
        Dim Start As DateTime = DateTime.Now
        txtZ.Text = obj.Add(txtX.Text, txtY.Text)
        For i = 1 To ITERATIONS
            obj.Add(txtX.Text, txtY.Text)
        Next
        txtTime3.Text = (DateTime.Now - Start).TotalSeconds
    End Sub
End Class
