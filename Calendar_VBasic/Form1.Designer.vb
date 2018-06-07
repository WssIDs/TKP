<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.set_bt = New System.Windows.Forms.Button()
        Me.ColorDialog1 = New System.Windows.Forms.ColorDialog()
        Me.get_tb = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.day_txt = New System.Windows.Forms.TextBox()
        Me.month_txt = New System.Windows.Forms.TextBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'set_bt
        '
        Me.set_bt.Location = New System.Drawing.Point(15, 57)
        Me.set_bt.Name = "set_bt"
        Me.set_bt.Size = New System.Drawing.Size(75, 23)
        Me.set_bt.TabIndex = 1
        Me.set_bt.Text = "Задать"
        Me.set_bt.UseVisualStyleBackColor = True
        '
        'get_tb
        '
        Me.get_tb.Location = New System.Drawing.Point(15, 86)
        Me.get_tb.Name = "get_tb"
        Me.get_tb.Size = New System.Drawing.Size(75, 23)
        Me.get_tb.TabIndex = 2
        Me.get_tb.Text = "Показать"
        Me.get_tb.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(12, 15)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(34, 13)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "День"
        '
        'day_txt
        '
        Me.day_txt.Location = New System.Drawing.Point(15, 31)
        Me.day_txt.Name = "day_txt"
        Me.day_txt.Size = New System.Drawing.Size(100, 20)
        Me.day_txt.TabIndex = 4
        '
        'month_txt
        '
        Me.month_txt.Location = New System.Drawing.Point(202, 31)
        Me.month_txt.Name = "month_txt"
        Me.month_txt.Size = New System.Drawing.Size(100, 20)
        Me.month_txt.TabIndex = 5
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(199, 15)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(40, 13)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "Месяц"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(332, 118)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.month_txt)
        Me.Controls.Add(Me.day_txt)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.get_tb)
        Me.Controls.Add(Me.set_bt)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents set_bt As Button
    Friend WithEvents ColorDialog1 As ColorDialog
    Friend WithEvents get_tb As Button
    Friend WithEvents Label1 As Label
    Friend WithEvents day_txt As TextBox
    Friend WithEvents month_txt As TextBox
    Friend WithEvents Label2 As Label
End Class
