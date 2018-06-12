Module Module1

    Sub Main()
        Dim obj As Object
        ' Создание объекта с указанным ProgId
        obj = CreateObject("SR_ATL2.FN01.1")
        Dim resInt = obj.Fun11(10, 30)
        Console.WriteLine("Fun11 10+30= " + resInt.ToString())
        Dim resFlt = obj.Fun12(5, 7, 12)
        Console.WriteLine("Fun12 5+7+12= " + resFlt.ToString())
        Dim resDbl = obj.Fun13(10)
        Console.WriteLine("Fun13 10*10= " + resDbl.ToString())
        Console.ReadKey()
    End Sub

End Module
