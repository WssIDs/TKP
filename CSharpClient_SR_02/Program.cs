using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace CSharpClient_SR_02
{
    class Program
    {
        static void Main(string[] args)
        {
            var atlPRType = Type.GetTypeFromProgID("SR_ATL2.FN01.1");

            if (atlPRType != null)
            {
                var obj = Activator.CreateInstance(atlPRType);

                if (obj != null)
                {

                    object[] methodDataFun11 = null;
                    methodDataFun11 = new object[2];
                    methodDataFun11[0] = 10;
                    methodDataFun11[1] = 30;

                    int resInt = (int)(atlPRType.InvokeMember("Fun11", BindingFlags.InvokeMethod, null, obj, methodDataFun11));

                    object[] methodDataFun12 = null;
                    methodDataFun12 = new object[3];
                    methodDataFun12[0] = 20;
                    methodDataFun12[1] = 30;
                    methodDataFun12[2] = 50;

                    float resFlt = (float)(atlPRType.InvokeMember("Fun12", BindingFlags.InvokeMethod, null, obj, methodDataFun12));

                    object[] methodDataFun13 = null;
                    methodDataFun13 = new object[1];
                    methodDataFun13[0] = 10;

                    double resDbl = (double)(atlPRType.InvokeMember("Fun13", BindingFlags.InvokeMethod, null, obj, methodDataFun13));

                    Console.WriteLine("Fun11 10+30= " + resInt.ToString());
                    Console.WriteLine("Fun12 20+30+50= " + resFlt.ToString());
                    Console.WriteLine("Fun13 10*10= " + resDbl.ToString());
                    Console.ReadKey();
                }
            }
        }
    }
}
