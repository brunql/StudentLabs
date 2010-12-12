namespace KM_Lab1
{
    partial class Form2
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
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.richTextBox2 = new System.Windows.Forms.RichTextBox();
            this.chartHystogramm = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.richTxtNumbers = new System.Windows.Forms.RichTextBox();
            this.btnPrev = new System.Windows.Forms.Button();
            this.labelMx = new System.Windows.Forms.Label();
            this.labelDx = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.chartHystogramm)).BeginInit();
            this.SuspendLayout();
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(12, 12);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(72, 117);
            this.richTextBox1.TabIndex = 0;
            this.richTextBox1.Text = "xi\n1\n3\n8\n11\n19\n29\n33";
            // 
            // richTextBox2
            // 
            this.richTextBox2.Location = new System.Drawing.Point(90, 12);
            this.richTextBox2.Name = "richTextBox2";
            this.richTextBox2.Size = new System.Drawing.Size(72, 117);
            this.richTextBox2.TabIndex = 1;
            this.richTextBox2.Text = "pi\n0.02\n0.26\n0.18\n0.32\n0.16\n0.02\n0.04";
            // 
            // chartHystogramm
            // 
            chartArea1.Name = "ChartArea1";
            this.chartHystogramm.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chartHystogramm.Legends.Add(legend1);
            this.chartHystogramm.Location = new System.Drawing.Point(168, 12);
            this.chartHystogramm.Name = "chartHystogramm";
            series1.ChartArea = "ChartArea1";
            series1.Legend = "Legend1";
            series1.Name = "Series1";
            this.chartHystogramm.Series.Add(series1);
            this.chartHystogramm.Size = new System.Drawing.Size(454, 378);
            this.chartHystogramm.TabIndex = 2;
            this.chartHystogramm.Text = "chart1";
            // 
            // richTxtNumbers
            // 
            this.richTxtNumbers.Location = new System.Drawing.Point(12, 135);
            this.richTxtNumbers.Name = "richTxtNumbers";
            this.richTxtNumbers.Size = new System.Drawing.Size(150, 284);
            this.richTxtNumbers.TabIndex = 3;
            this.richTxtNumbers.Text = "";
            // 
            // btnPrev
            // 
            this.btnPrev.Location = new System.Drawing.Point(547, 396);
            this.btnPrev.Name = "btnPrev";
            this.btnPrev.Size = new System.Drawing.Size(75, 23);
            this.btnPrev.TabIndex = 4;
            this.btnPrev.Text = "Previous";
            this.btnPrev.UseVisualStyleBackColor = true;
            this.btnPrev.Click += new System.EventHandler(this.btnPrev_Click);
            // 
            // labelMx
            // 
            this.labelMx.AutoSize = true;
            this.labelMx.Location = new System.Drawing.Point(168, 393);
            this.labelMx.Name = "labelMx";
            this.labelMx.Size = new System.Drawing.Size(33, 13);
            this.labelMx.TabIndex = 5;
            this.labelMx.Text = "Mx = ";
            // 
            // labelDx
            // 
            this.labelDx.AutoSize = true;
            this.labelDx.Location = new System.Drawing.Point(167, 410);
            this.labelDx.Name = "labelDx";
            this.labelDx.Size = new System.Drawing.Size(32, 13);
            this.labelDx.TabIndex = 6;
            this.labelDx.Text = "Dx = ";
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(634, 431);
            this.Controls.Add(this.labelDx);
            this.Controls.Add(this.labelMx);
            this.Controls.Add(this.btnPrev);
            this.Controls.Add(this.richTxtNumbers);
            this.Controls.Add(this.chartHystogramm);
            this.Controls.Add(this.richTextBox2);
            this.Controls.Add(this.richTextBox1);
            this.Name = "Form2";
            this.Text = "KM_Lab1.2";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form2_FormClosed);
            ((System.ComponentModel.ISupportInitialize)(this.chartHystogramm)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.RichTextBox richTextBox2;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartHystogramm;
        private System.Windows.Forms.RichTextBox richTxtNumbers;
        private System.Windows.Forms.Button btnPrev;
        private System.Windows.Forms.Label labelMx;
        private System.Windows.Forms.Label labelDx;
    }
}