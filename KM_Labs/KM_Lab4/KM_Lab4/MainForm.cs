using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace KM_Lab4
{
    public partial class MainForm : Form
    {
        const int N = 1000;
        const double lambdaForTCameSecs = 60;
        const double lambdaForTServiceSecs = 30;

        Random r = new Random();

        public MainForm()
        {
            InitializeComponent();

            chartClient.Series.Clear();
            chartCassa.Series.Clear();

            chartClient.Series.Add("График клиента");
            chartCassa.Series.Add("График кассира");

            chartClient.Series["График клиента"].XValueType = System.Windows.Forms.DataVisualization.Charting.ChartValueType.Time;            
            chartCassa.Series["График кассира"].XValueType = System.Windows.Forms.DataVisualization.Charting.ChartValueType.Time;            


            List<DateTime> ListTStart = new List<DateTime>();

            DateTime TStartWorkKassa = new DateTime(2010, 11, 2, 8, 0, 0, 0); // 8:00 2.11.2010

            DateTime TCameToKassa = new DateTime(2010, 11, 2, 8, 0, 0, 0); // 8:00 2.11.2010
            DateTime TStart = new DateTime(2010, 11, 2, 8, 0, 0, 0); // 8:00 2.11.2010            
            DateTime TOut = new DateTime(2010, 11, 2, 8, 0, 0, 0);

            DateTime TFullDownTime = new DateTime();
            DateTime TMaxTimeInQueue = new DateTime();
            DateTime TMinTimeInQueue = new DateTime(2011, 11, 2, 8, 0, 0, 0);

            int TServiceSecs = 0;
            double QueueSizeAVG = 0;
            int QueueMaxSize = 0;
            double TInQueueAVG_Secs = 0;           

            double TimeInWorkInSeries_Secs = 0;

            double TMaxTimeInWork_Secs = 0;
            double TMinTimeInWork_Secs = 10000;

            double TQueueSizeAndTimeInQueueAVG = 0;

            DateTime TCassaWorkingStart = new DateTime();
            DateTime TCassaWorkingEnd = new DateTime();

            for (int n = 0; n < N; n++)
            {
                int TCameSecs = (int)(-lambdaForTCameSecs * Math.Log(r.NextDouble()));
                TCameToKassa = TCameToKassa.AddSeconds(TCameSecs);

                // Eval downtime between previous TOut and now TCameToKassa
                DateTime TDowntime = new DateTime();
                long downtimeTicks = TCameToKassa.Ticks - TOut.Ticks;
                if (downtimeTicks >= 0)
                {
                    TDowntime = new DateTime(downtimeTicks);
                    TFullDownTime = TFullDownTime.AddTicks(downtimeTicks);
                    TimeInWorkInSeries_Secs = 0;
                }//if downtimeTicks < 0 TDowntime == 00:00 and people now in queue                

                
                TStart = new DateTime(TCameToKassa.Ticks);
                if (TStart < TOut)
                {
                    TStart = new DateTime(TOut.Ticks);
                }
                ListTStart.Add(TStart);

                TServiceSecs = (int)(-lambdaForTServiceSecs * Math.Log(r.NextDouble()));
                TOut = TStart.AddSeconds(TServiceSecs);

                // Evil code
                DateTime TKassaWorking = new DateTime(TOut.Ticks - TCameToKassa.Ticks);
                TimeInWorkInSeries_Secs += TKassaWorking.Minute * 60 + TKassaWorking.Second;

                if (TimeInWorkInSeries_Secs > TMaxTimeInWork_Secs)
                {
                    TMaxTimeInWork_Secs = TimeInWorkInSeries_Secs;
                }
                if (TimeInWorkInSeries_Secs != 0 && TimeInWorkInSeries_Secs < TMinTimeInWork_Secs)
                {
                    TMinTimeInWork_Secs = TimeInWorkInSeries_Secs;
                }

                // Find numder of peoples in queue
                int QueueSize = 0;
                for (int i = 0; i <= n; i++)
                {
                    if (ListTStart[i] > TCameToKassa)
                    {
                        QueueSize++;
                    }
                }
                QueueSizeAVG += QueueSize;
                if (QueueSize > QueueMaxSize)
                {
                    QueueMaxSize = QueueSize;
                }                
                
                DateTime TCame = new DateTime(2010, 11, 2, 0, 0, 0, 0).AddSeconds(TCameSecs);
                DateTime TService = new DateTime(2010, 11, 2, 0, 0, 0, 0).AddSeconds(TServiceSecs);

                // Draw graphics
                chartClient.Series["График клиента"].Points.AddXY(TCameToKassa, QueueSize);
                if (QueueSize == 0)
                {
                    chartCassa.Series["График кассира"].Points.AddXY(TCameToKassa, 0);
                }
                else
                {
                    chartCassa.Series["График кассира"].Points.AddXY(TCameToKassa, 1);
                }
                

                // Eval time in queue
                DateTime TInQueue = new DateTime();
                long inQueueTicks = TStart.Ticks - TCameToKassa.Ticks;
                if (inQueueTicks > 0)
                {
                    TInQueue = new DateTime(inQueueTicks);
                }

                if (TInQueue > TMaxTimeInQueue)
                {
                    TMaxTimeInQueue = TInQueue;
                }
                if (TInQueue < TMinTimeInQueue && TInQueue.Ticks > 0)
                {
                    TMinTimeInQueue = TInQueue;
                }

                TInQueueAVG_Secs += TInQueue.Minute * 60 + TInQueue.Second;
                TQueueSizeAndTimeInQueueAVG += QueueSize * (TInQueue.Minute * 60 + TInQueue.Second);
                //listBoxEval.Items.Add("TInQueue.Minute=" + TInQueue.Minute.ToString() + " " + "TInQueue.Second=" + TInQueue.Second.ToString());
        
                dataGridView.Rows.Add(n,
                    TCame.ToString("mm:ss"),
                    TService.ToString("mm:ss"),
                    TCameToKassa.ToLongTimeString(),
                    TStart.ToLongTimeString(),
                    TOut.ToLongTimeString(),
                    QueueSize,
                    TInQueue.ToString("mm:ss"),
                    TDowntime.ToString("mm:ss")
                    );
            }


            // Eval a lot...            
            DateTime TWorkingKassa = new DateTime(TOut.Ticks - TStartWorkKassa.Ticks);
            double percents = Math.Round((double)TFullDownTime.Ticks / TWorkingKassa.Ticks * 100.0, 2);
            QueueSizeAVG = Math.Round(QueueSizeAVG / N, 2);

            TInQueueAVG_Secs = Math.Round(TInQueueAVG_Secs / N, 4);

            TQueueSizeAndTimeInQueueAVG = Math.Round(TQueueSizeAndTimeInQueueAVG / (TWorkingKassa.Hour*3600 + TWorkingKassa.Minute * 60 + TWorkingKassa.Second), 3);

            listBoxEval.Items.Add("1. Длительность моделируемого периода (время работы кассового зала): ");
            listBoxEval.Items.Add("\t" + TWorkingKassa.ToLongTimeString());
            listBoxEval.Items.Add("2. Коэффициент занятости устройства обслуживания (долю простоя кассира от общего времени работы). Ответ выдать в процентах: ");
            listBoxEval.Items.Add("\t" + percents.ToString() + "%");
            listBoxEval.Items.Add("3. Среднее число требований в очереди (среднее число клиентов банка, стоящих в очереди): ");
            listBoxEval.Items.Add("\t" + QueueSizeAVG.ToString());
            listBoxEval.Items.Add("4. Максимальная и минимальная задержка требования в очереди (максимальное и минимальное время нахождения клиента в очереди). Ответ выдать в мин:сек.");
            listBoxEval.Items.Add("\t Max=" + TMaxTimeInQueue.ToString("mm:ss") + "\t Min=" + TMinTimeInQueue.ToString("mm:ss"));
            listBoxEval.Items.Add("5. Максимальная длина очереди (максимальное кол-во клиентов, стоящих в очереди).");
            listBoxEval.Items.Add("\t" + QueueMaxSize.ToString());
            listBoxEval.Items.Add("6. Среднее время нахождения клиента в очереди (от общего количества времени, проведенного клиентом в банке). Ответ выдать в мин:сек.");
            listBoxEval.Items.Add("\t" + new DateTime().AddSeconds((int)TInQueueAVG_Secs).ToString("mm:ss"));
            listBoxEval.Items.Add("7. Максимальное и минимальное время работы устройства обслуживания (кассира) без перерыва (Ответ выдать в мин:сек).");
            listBoxEval.Items.Add("\t Max=" + new DateTime().AddSeconds((int)TMaxTimeInWork_Secs).ToString("mm:ss") +
                " Min=" + new DateTime().AddSeconds((int)TMinTimeInWork_Secs).ToString("mm:ss"));
            listBoxEval.Items.Add("8. Среднее по времени число требований в системе (среднее по времени число клиентов в зале).");
            listBoxEval.Items.Add("\t" + TQueueSizeAndTimeInQueueAVG);                       
        }
    }
}
