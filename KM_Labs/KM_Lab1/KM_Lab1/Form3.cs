using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace KM_Lab1
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();

            RandomGenerator.Init(Math.PI * 100555555600);
            RandomGenerator.Fill(1000);


            const double scaleX = 6; // b - a
            const double scaleY = 1; // M

            double k1 = k(0, 0.25, 2, 0);
            double b1 = b(0, 0.25, 2, 0);
            double k2 = k(2, 0, 4, 0.25);
            double b2 = b(2, 0, 4, 0.25);
            double k3 = k(4, 0, 6, 0.5);
            double b3 = b(4, 0, 6, 0.5);

            var r = new Random();
            var hit = new List<double>();

            for (int i = 0; i < RandomGenerator.N; i++)
            {
                double x = scaleX * i / RandomGenerator.N;
                double y = RandomGenerator.randArr[i] * scaleY;
                
                if (x >= 0 && x < 2)
                {
                    if(y < f(x, k1, b1)){
                        hit.Add(x);
                    }
                }
                else if(x >=2 && x < 4)
                {
                    if (y < f(x, k2, b2))
                    {
                        hit.Add(x);
                    }
                }
                else if (x >= 4 && x < 6)
                {
                    if (y < f(x, k3, b3))
                    {
                        hit.Add(x);
                    }
                }
            }

            for (int i = 0; i < hit.Count; i++)
            {
                txtRandHited.Text += hit[i] + Environment.NewLine;
            }

            double mx = RandomGenerator.EvalMx(hit);
            labelMx.Text += mx.ToString();
            labelDx.Text += RandomGenerator.EvalDx(hit, mx);

            const double stepX = 0.2;
            var resultHystogramm = new int[(int)(scaleX / stepX)];
            int index = 0;
            for (double x = 0; x < scaleX - stepX; x += stepX)
            {
                double start = x, end = start + stepX;
               
                for (int i = 0; i < hit.Count; i++)
                {
                    if (hit[i] >= start && hit[i] < end)
                    {
                        resultHystogramm[index]++;
                    }
                }
                index++;
            }


            chartHystogramm.Series[0].LegendText = "Относительная частота попадания";
            for (int i = 0; i < resultHystogramm.Length; i++)
            {
                chartHystogramm.Series[0].Points.AddY((double)resultHystogramm[i] / resultHystogramm.Length);
            }

        }

        private double f(double x, double k, double b)
        {
            return k * x + b;
        }

        private double k(double x1, double y1, double x2, double y2)
        {
            return (y2 - y1) / (x2 - x1);
        }

        private double b(double x1, double y1, double x2, double y2)
        {
            return y1 - (y2 - y1) / (x2 - x1) * x1;
        }
    }
}
