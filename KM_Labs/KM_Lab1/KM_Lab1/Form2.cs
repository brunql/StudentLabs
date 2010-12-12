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
    public partial class Form2 : Form
    {
        private Form parentForm;

        public Form2(Form parent)
        {
            parentForm = parent;

            InitializeComponent();
            chartHystogramm.Series[0].LegendText = "Относительная частота попадания";
            RandomGenerate();
        }

        List<int> randArr2 = new List<int>();

        private void RandomGenerate()
        {
            // Var 20
            int[] xi = { 1, 3, 8, 11, 19, 29, 33 };
            double[] pi = { 0.02, 0.26, 0.18, 0.32, 0.16, 0.02, 0.04 };
            int[] result = new int[pi.Length];

            for (int r = 0; r < RandomGenerator.N; r++)
            {
                double randomNum = RandomGenerator.randArr[r];

                double start = 0, end = pi[0];
                int findIndex = 0;
                for (int i = 0; i < pi.Length; i++)
                {
                    if (randomNum >= start && randomNum < end)
                    {
                        findIndex = i;
                        break;
                    }
                    if (i < pi.Length-1)
                    {
                        start += pi[i];
                        end += pi[i + 1];
                    }
                }
                result[findIndex]++;
                randArr2.Add(xi[findIndex]);
            }

            double mx = 0;
            for (int i = 0; i < randArr2.Count; i++)
            {
                mx += randArr2[i];
            }
            mx /= randArr2.Count;

            double dx = 0;
            for (int i = 0; i < randArr2.Count; i++)
            {
                dx += Math.Pow(randArr2[i] - mx, 2);
            }
            dx /= randArr2.Count - 1;

            labelMx.Text = mx.ToString();
            labelDx.Text = dx.ToString();




            richTxtNumbers.Text = "Numbers:" + Environment.NewLine;
            for (int i = 0; i < randArr2.Count; i++)
            {
                richTxtNumbers.Text += randArr2[i] + Environment.NewLine;
            }

            for (int i = 0; i < result.Length; i++)
            {
                chartHystogramm.Series[0].Points.AddY(result[i]/1000.0);
            }
        }

        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
            Environment.Exit(93);
        }

        private void btnPrev_Click(object sender, EventArgs e)
        {
            parentForm.Show();
            this.Hide();
        }
    }
}
