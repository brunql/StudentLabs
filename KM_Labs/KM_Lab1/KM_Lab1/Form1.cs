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
    public partial class Form1 : Form
    {
        Form2 form2;

        public Form1()
        {
            InitializeComponent();           
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            RandomGenerator.Init(Math.PI * 100555555600);
            richTxtNumbers.Text = "Random numbers:" + Environment.NewLine;
            RandomGenerator.Fill(1000);
             
            for (int i = 0; i < RandomGenerator.N; i++)
            {
                richTxtNumbers.Text += RandomGenerator.randArr[i].ToString() + Environment.NewLine;
            }
            labelMx.Text += Math.Round(RandomGenerator.Mx, 4).ToString();
            labelDx.Text += Math.Round(RandomGenerator.Dx, 4).ToString();
            

            richTxtTable.Text = "Интервал\t Частота попаданий\t Относительная частота попадания" + Environment.NewLine;
            chartHystogramm.Series[0].LegendText = "Относительная частота попадания";
            for (int i = 0; i < 10; i++)
            {
                double start = i / 10.0;
                double end = (i+1) / 10.0;

                int n = 0;
                for (int j = 0; j < RandomGenerator.N; j++)
                {
                    if (RandomGenerator.randArr[j] > start && RandomGenerator.randArr[j] <= end)
                    {
                        n++;
                    }
                }
                double freq = (double)n / RandomGenerator.N;
                richTxtTable.Text += string.Format("({0:0.0},{1:0.0})\t\t {2}\t\t\t {3}" + Environment.NewLine, 
                    start, end, n, freq);

                chartHystogramm.Series[0].Points.AddY(freq);
            }

            

        }



        private void btnNext_Click(object sender, EventArgs e)
        {
            if (form2 == null)
            {
                form2 = new Form2(this);
            }
            form2.Show();
            this.Hide();
        }
    }
}
