namespace KM_Lab3
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
            this.txtSteps = new System.Windows.Forms.TextBox();
            this.chartHystogramm = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.labelMx = new System.Windows.Forms.Label();
            this.labelDx = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.chartHystogramm)).BeginInit();
            this.SuspendLayout();
            // 
            // txtSteps
            // 
            this.txtSteps.Location = new System.Drawing.Point(12, 12);
            this.txtSteps.Multiline = true;
            this.txtSteps.Name = "txtSteps";
            this.txtSteps.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtSteps.Size = new System.Drawing.Size(132, 218);
            this.txtSteps.TabIndex = 0;
            // 
            // chartHystogramm
            // 
            chartArea1.Name = "ChartArea1";
            this.chartHystogramm.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chartHystogramm.Legends.Add(legend1);
            this.chartHystogramm.Location = new System.Drawing.Point(150, 12);
            this.chartHystogramm.Name = "chartHystogramm";
            series1.ChartArea = "ChartArea1";
            series1.Legend = "Legend1";
            series1.Name = "Series1";
            this.chartHystogramm.Series.Add(series1);
            this.chartHystogramm.Size = new System.Drawing.Size(467, 280);
            this.chartHystogramm.TabIndex = 1;
            this.chartHystogramm.Text = "chart1";
            // 
            // labelMx
            // 
            this.labelMx.AutoSize = true;
            this.labelMx.Location = new System.Drawing.Point(13, 237);
            this.labelMx.Name = "labelMx";
            this.labelMx.Size = new System.Drawing.Size(33, 13);
            this.labelMx.TabIndex = 2;
            this.labelMx.Text = "Mx = ";
            // 
            // labelDx
            // 
            this.labelDx.AutoSize = true;
            this.labelDx.Location = new System.Drawing.Point(12, 254);
            this.labelDx.Name = "labelDx";
            this.labelDx.Size = new System.Drawing.Size(32, 13);
            this.labelDx.TabIndex = 3;
            this.labelDx.Text = "Dx = ";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(629, 301);
            this.Controls.Add(this.labelDx);
            this.Controls.Add(this.labelMx);
            this.Controls.Add(this.chartHystogramm);
            this.Controls.Add(this.txtSteps);
            this.Name = "MainForm";
            this.Text = "KM Lab #3";
            ((System.ComponentModel.ISupportInitialize)(this.chartHystogramm)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtSteps;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartHystogramm;
        private System.Windows.Forms.Label labelMx;
        private System.Windows.Forms.Label labelDx;
    }
}

