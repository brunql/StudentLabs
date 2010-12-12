using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace KM_Lab2
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();

            chart1.Series.Clear();
            chart1.Series.Add("Random exp");
            chart1.Series.Add("Exp");


            var R = new Random();
            var X = new List<double>();

            for (int i = 0; i < 1000; i++)
            {
                double r = R.NextDouble();
                while (r == 0) { r = R.NextDouble(); }
                double x = - 0.4 * Math.Log(r, Math.E);
                X.Add(x);
            }

            for (int i = 0; i < X.Count; i++)
            {
                txtX.Text += X[i].ToString() + Environment.NewLine;                
            }

            labelFormula.Text += X.Max().ToString() + Environment.NewLine;

            const int k = 16; // number of intervals

            double scaleX = X.Max();
            double stepX = scaleX / k;
            int L = k;
            var vk = new double[L];
            int index = 0;
            double Hi2 = 0;

            for (double x = 0; x < scaleX - stepX; x += stepX)
            {
                double start = x, end = start + stepX;

                for (int i = 0; i < X.Count; i++)
                {
                    if (X[i] >= start && X[i] < end)
                    {
                        vk[index]++;
                    }
                }

                // Find X^2
                double pk = F(end) - F(start);
                int n = X.Count;
                Hi2 += Math.Pow(vk[index] - n * pk, 2) / n * pk;
                

                index++;
            }
            txtX.Text = X.Max().ToString() + Environment.NewLine + txtX.Text;

            labelHi2.Text += Hi2.ToString();

            for (int i = 0; i < vk.Length; i++)
            {
                chart1.Series["Random exp"].Points.AddY(vk[i]);
            }           
        }

        private double F(double x)
        {
            return (1 - Math.Exp(-x / 0.4));
        }
    }
}
