namespace KM_Lab1
{
    partial class Form1
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
            this.richTxtNumbers = new System.Windows.Forms.RichTextBox();
            this.labelMx = new System.Windows.Forms.Label();
            this.labelDx = new System.Windows.Forms.Label();
            this.richTxtTable = new System.Windows.Forms.RichTextBox();
            this.chartHystogramm = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.btnNext = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.chartHystogramm)).BeginInit();
            this.SuspendLayout();
            // 
            // richTxtNumbers
            // 
            this.richTxtNumbers.Location = new System.Drawing.Point(12, 41);
            this.richTxtNumbers.Name = "richTxtNumbers";
            this.richTxtNumbers.Size = new System.Drawing.Size(143, 440);
            this.richTxtNumbers.TabIndex = 0;
            this.richTxtNumbers.Text = "Numbers";
            // 
            // labelMx
            // 
            this.labelMx.AutoSize = true;
            this.labelMx.Location = new System.Drawing.Point(11, 485);
            this.labelMx.Name = "labelMx";
            this.labelMx.Size = new System.Drawing.Size(33, 13);
            this.labelMx.TabIndex = 1;
            this.labelMx.Text = "Mx = ";
            // 
            // labelDx
            // 
            this.labelDx.AutoSize = true;
            this.labelDx.Location = new System.Drawing.Point(12, 498);
            this.labelDx.Name = "labelDx";
            this.labelDx.Size = new System.Drawing.Size(32, 13);
            this.labelDx.TabIndex = 2;
            this.labelDx.Text = "Dx = ";
            // 
            // richTxtTable
            // 
            this.richTxtTable.Location = new System.Drawing.Point(175, 41);
            this.richTxtTable.Name = "richTxtTable";
            this.richTxtTable.Size = new System.Drawing.Size(604, 219);
            this.richTxtTable.TabIndex = 3;
            this.richTxtTable.Text = "";
            // 
            // chartHystogramm
            // 
            chartArea1.Name = "ChartArea1";
            this.chartHystogramm.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chartHystogramm.Legends.Add(legend1);
            this.chartHystogramm.Location = new System.Drawing.Point(175, 277);
            this.chartHystogramm.Name = "chartHystogramm";
            series1.ChartArea = "ChartArea1";
            series1.Legend = "Legend1";
            series1.Name = "Series1";
            this.chartHystogramm.Series.Add(series1);
            this.chartHystogramm.Size = new System.Drawing.Size(604, 204);
            this.chartHystogramm.TabIndex = 4;
            this.chartHystogramm.Text = "chart1";
            // 
            // btnNext
            // 
            this.btnNext.Location = new System.Drawing.Point(704, 485);
            this.btnNext.Name = "btnNext";
            this.btnNext.Size = new System.Drawing.Size(75, 23);
            this.btnNext.TabIndex = 5;
            this.btnNext.Text = "Next";
            this.btnNext.UseVisualStyleBackColor = true;
            this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(805, 520);
            this.Controls.Add(this.btnNext);
            this.Controls.Add(this.chartHystogramm);
            this.Controls.Add(this.richTxtTable);
            this.Controls.Add(this.labelDx);
            this.Controls.Add(this.labelMx);
            this.Controls.Add(this.richTxtNumbers);
            this.Name = "Form1";
            this.Text = "KM_Lab1.1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.chartHystogramm)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox richTxtNumbers;
        private System.Windows.Forms.Label labelMx;
        private System.Windows.Forms.Label labelDx;
        private System.Windows.Forms.RichTextBox richTxtTable;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartHystogramm;
        private System.Windows.Forms.Button btnNext;
    }
}

