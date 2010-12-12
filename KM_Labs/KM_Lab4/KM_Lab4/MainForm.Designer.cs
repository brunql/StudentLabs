namespace KM_Lab4
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.dataGridView = new System.Windows.Forms.DataGridView();
            this.ColumnN = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ColumnTCame = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ColumnTService = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ColumnTCameToKassa = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ColumnTStart = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ColumnTOut = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ColumnQueueSize = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ColumnTInQueue = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ColumnTDowntime = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPageTable = new System.Windows.Forms.TabPage();
            this.tabPageEvaluated = new System.Windows.Forms.TabPage();
            this.listBoxEval = new System.Windows.Forms.ListBox();
            this.tabPageGraphics = new System.Windows.Forms.TabPage();
            this.chartClient = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.chartCassa = new System.Windows.Forms.DataVisualization.Charting.Chart();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
            this.tabControl1.SuspendLayout();
            this.tabPageTable.SuspendLayout();
            this.tabPageEvaluated.SuspendLayout();
            this.tabPageGraphics.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chartClient)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chartCassa)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView
            // 
            this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ColumnN,
            this.ColumnTCame,
            this.ColumnTService,
            this.ColumnTCameToKassa,
            this.ColumnTStart,
            this.ColumnTOut,
            this.ColumnQueueSize,
            this.ColumnTInQueue,
            this.ColumnTDowntime});
            this.dataGridView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridView.Location = new System.Drawing.Point(3, 3);
            this.dataGridView.Name = "dataGridView";
            this.dataGridView.Size = new System.Drawing.Size(680, 286);
            this.dataGridView.TabIndex = 0;
            // 
            // ColumnN
            // 
            this.ColumnN.HeaderText = "№ клиента";
            this.ColumnN.Name = "ColumnN";
            // 
            // ColumnTCame
            // 
            this.ColumnTCame.HeaderText = "Время прибытия";
            this.ColumnTCame.Name = "ColumnTCame";
            // 
            // ColumnTService
            // 
            this.ColumnTService.HeaderText = "Время обслуживания";
            this.ColumnTService.Name = "ColumnTService";
            // 
            // ColumnTCameToKassa
            // 
            this.ColumnTCameToKassa.HeaderText = "Время прихода на кассу";
            this.ColumnTCameToKassa.Name = "ColumnTCameToKassa";
            // 
            // ColumnTStart
            // 
            this.ColumnTStart.HeaderText = "Время начала обслуживания";
            this.ColumnTStart.Name = "ColumnTStart";
            // 
            // ColumnTOut
            // 
            this.ColumnTOut.HeaderText = "Время ухода";
            this.ColumnTOut.Name = "ColumnTOut";
            // 
            // ColumnQueueSize
            // 
            this.ColumnQueueSize.HeaderText = "Длина очереди";
            this.ColumnQueueSize.Name = "ColumnQueueSize";
            // 
            // ColumnTInQueue
            // 
            this.ColumnTInQueue.HeaderText = "Время нахождения в очереди";
            this.ColumnTInQueue.Name = "ColumnTInQueue";
            // 
            // ColumnTDowntime
            // 
            this.ColumnTDowntime.HeaderText = "Время простоя";
            this.ColumnTDowntime.Name = "ColumnTDowntime";
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPageTable);
            this.tabControl1.Controls.Add(this.tabPageEvaluated);
            this.tabControl1.Controls.Add(this.tabPageGraphics);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(694, 318);
            this.tabControl1.TabIndex = 1;
            // 
            // tabPageTable
            // 
            this.tabPageTable.Controls.Add(this.dataGridView);
            this.tabPageTable.Location = new System.Drawing.Point(4, 22);
            this.tabPageTable.Name = "tabPageTable";
            this.tabPageTable.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageTable.Size = new System.Drawing.Size(686, 292);
            this.tabPageTable.TabIndex = 0;
            this.tabPageTable.Text = "Таблица";
            this.tabPageTable.UseVisualStyleBackColor = true;
            // 
            // tabPageEvaluated
            // 
            this.tabPageEvaluated.Controls.Add(this.listBoxEval);
            this.tabPageEvaluated.Location = new System.Drawing.Point(4, 22);
            this.tabPageEvaluated.Name = "tabPageEvaluated";
            this.tabPageEvaluated.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageEvaluated.Size = new System.Drawing.Size(686, 292);
            this.tabPageEvaluated.TabIndex = 1;
            this.tabPageEvaluated.Text = "Расчитано";
            this.tabPageEvaluated.UseVisualStyleBackColor = true;
            // 
            // listBoxEval
            // 
            this.listBoxEval.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listBoxEval.FormattingEnabled = true;
            this.listBoxEval.Items.AddRange(new object[] {
            " "});
            this.listBoxEval.Location = new System.Drawing.Point(3, 3);
            this.listBoxEval.Name = "listBoxEval";
            this.listBoxEval.Size = new System.Drawing.Size(680, 286);
            this.listBoxEval.TabIndex = 0;
            // 
            // tabPageGraphics
            // 
            this.tabPageGraphics.Controls.Add(this.splitContainer1);
            this.tabPageGraphics.Location = new System.Drawing.Point(4, 22);
            this.tabPageGraphics.Name = "tabPageGraphics";
            this.tabPageGraphics.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageGraphics.Size = new System.Drawing.Size(686, 292);
            this.tabPageGraphics.TabIndex = 2;
            this.tabPageGraphics.Text = "Графики";
            this.tabPageGraphics.UseVisualStyleBackColor = true;
            // 
            // chartClient
            // 
            chartArea1.Name = "ChartArea1";
            this.chartClient.ChartAreas.Add(chartArea1);
            this.chartClient.Dock = System.Windows.Forms.DockStyle.Fill;
            legend1.Name = "Legend1";
            this.chartClient.Legends.Add(legend1);
            this.chartClient.Location = new System.Drawing.Point(0, 0);
            this.chartClient.Name = "chartClient";
            series1.ChartArea = "ChartArea1";
            series1.Legend = "Legend1";
            series1.Name = "Client";
            series1.XValueType = System.Windows.Forms.DataVisualization.Charting.ChartValueType.DateTime;
            this.chartClient.Series.Add(series1);
            this.chartClient.Size = new System.Drawing.Size(680, 143);
            this.chartClient.TabIndex = 0;
            this.chartClient.Text = "chart1";
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(3, 3);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.chartClient);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.chartCassa);
            this.splitContainer1.Size = new System.Drawing.Size(680, 286);
            this.splitContainer1.SplitterDistance = 143;
            this.splitContainer1.TabIndex = 1;
            // 
            // chartCassa
            // 
            chartArea2.Name = "ChartArea1";
            this.chartCassa.ChartAreas.Add(chartArea2);
            this.chartCassa.Dock = System.Windows.Forms.DockStyle.Fill;
            legend2.Name = "Legend1";
            this.chartCassa.Legends.Add(legend2);
            this.chartCassa.Location = new System.Drawing.Point(0, 0);
            this.chartCassa.Name = "chartCassa";
            series2.ChartArea = "ChartArea1";
            series2.Legend = "Legend1";
            series2.Name = "Cassa";
            this.chartCassa.Series.Add(series2);
            this.chartCassa.Size = new System.Drawing.Size(680, 139);
            this.chartCassa.TabIndex = 0;
            this.chartCassa.Text = "chart2";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(694, 318);
            this.Controls.Add(this.tabControl1);
            this.Name = "MainForm";
            this.Text = "KM Lab #4";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
            this.tabControl1.ResumeLayout(false);
            this.tabPageTable.ResumeLayout(false);
            this.tabPageEvaluated.ResumeLayout(false);
            this.tabPageGraphics.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.chartClient)).EndInit();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.chartCassa)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView;
        private System.Windows.Forms.DataGridViewTextBoxColumn ColumnN;
        private System.Windows.Forms.DataGridViewTextBoxColumn ColumnTCame;
        private System.Windows.Forms.DataGridViewTextBoxColumn ColumnTService;
        private System.Windows.Forms.DataGridViewTextBoxColumn ColumnTCameToKassa;
        private System.Windows.Forms.DataGridViewTextBoxColumn ColumnTStart;
        private System.Windows.Forms.DataGridViewTextBoxColumn ColumnTOut;
        private System.Windows.Forms.DataGridViewTextBoxColumn ColumnQueueSize;
        private System.Windows.Forms.DataGridViewTextBoxColumn ColumnTInQueue;
        private System.Windows.Forms.DataGridViewTextBoxColumn ColumnTDowntime;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPageTable;
        private System.Windows.Forms.TabPage tabPageEvaluated;
        private System.Windows.Forms.ListBox listBoxEval;
        private System.Windows.Forms.TabPage tabPageGraphics;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartClient;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartCassa;
    }
}

