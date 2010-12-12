using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace KM_Lab3
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();


            List<double> lengths = new List<double>();

            // P(j) = exp(-j);
            Random r = new Random();
            double scaleX = 0;
            double min = 0;
            double max = 0;

            for (int i = 0; i < 1000; i++)
            {
                int stepsCount = 0;
                double length = 0;
                for (; stepsCount < 10; )
                {
                    double j = r.NextDouble();
                    double check = r.NextDouble();

                    if (check < P(j))
                    {
                        stepsCount++;
                        length += j;
                    }
                }
                lengths.Add(length);
                if (length > max)
                {
                    max = length;
                }
                if (length < min)
                {
                    min = length;
                }
            }


            for (int i = 0; i < lengths.Count; i++)
            {
                txtSteps.Text += lengths[i].ToString() + Environment.NewLine;
            }

            double mx = 0;
            for (int i = 0; i < lengths.Count; i++)
            {
                mx += lengths[i];
            }
            mx /= lengths.Count;
            

            double dx = 0;
            for (int i = 0; i < lengths.Count; i++)
            {
                dx += Math.Pow(lengths[i] - mx, 2);
            }
            dx /= lengths.Count - 1;

            labelMx.Text += mx.ToString();
            labelDx.Text += dx.ToString();

            scaleX = max;
            double stepX = (max - min) / 11;

            var resultHystogramm = new int[(int)(scaleX / stepX)];
            int index = 0;

            //labelMx.Text = resultHystogramm.Length.ToString();

            for (double x = 0; x < scaleX - stepX; x += stepX)
            {

                double start = x, end = start + stepX;
                for (int i = 0; i < lengths.Count; i++)
                {
                    if (lengths[i] >= start && lengths[i] < end)
                    {
                        resultHystogramm[index]++;
                    }
                }
                index++;
            }

            chartHystogramm.Series[0].LegendText = "Относительная частота попадания";
            chartHystogramm.Series.Add("Norm");
            chartHystogramm.Series["Norm"].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;

            for (int i = 0; i < resultHystogramm.Length; i++)
            {
                chartHystogramm.Series[0].Points.AddXY(i * stepX, (double)resultHystogramm[i] / 1000);
            }
            for(double x=0; x < max; x += 0.01){
                chartHystogramm.Series["Norm"].Points.AddXY(x,
                    (1 / (Math.Sqrt(2 * Math.PI * dx))) * Math.Exp(-Math.Pow((x - mx), 2) / (2 * dx))
                    );
            }
        }

        private double P(double j)
        {
            return Math.Exp(-j);
        }

    }
}
