namespace AutoPark
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            tBox_model = new TextBox();
            tBox_color = new TextBox();
            tBox_engine = new TextBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            dgv_carList = new DataGridView();
            btn_add = new Button();
            btn_remove = new Button();
            btn_clearAll = new Button();
            btn_orderByName = new Button();
            btn_save = new Button();
            btn_load = new Button();
            numericUpDown_id = new NumericUpDown();
            numericUpDown_price = new NumericUpDown();
            numericUpDown_year = new NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)dgv_carList).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown_id).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown_price).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown_year).BeginInit();
            SuspendLayout();
            // 
            // tBox_model
            // 
            tBox_model.Location = new Point(92, 108);
            tBox_model.Name = "tBox_model";
            tBox_model.Size = new Size(125, 27);
            tBox_model.TabIndex = 0;
            tBox_model.TextChanged += textBox1_TextChanged;
            // 
            // tBox_color
            // 
            tBox_color.Location = new Point(92, 174);
            tBox_color.Name = "tBox_color";
            tBox_color.Size = new Size(125, 27);
            tBox_color.TabIndex = 2;
            // 
            // tBox_engine
            // 
            tBox_engine.Location = new Point(92, 372);
            tBox_engine.Name = "tBox_engine";
            tBox_engine.Size = new Size(125, 27);
            tBox_engine.TabIndex = 5;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(40, 45);
            label1.Name = "label1";
            label1.Size = new Size(27, 20);
            label1.TabIndex = 8;
            label1.Text = "ID:";
            label1.Click += label1_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(12, 111);
            label2.Name = "label2";
            label2.Size = new Size(55, 20);
            label2.TabIndex = 9;
            label2.Text = "Model:";
            label2.Click += label2_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(19, 177);
            label3.Name = "label3";
            label3.Size = new Size(48, 20);
            label3.TabIndex = 10;
            label3.Text = "Color:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(27, 243);
            label4.Name = "label4";
            label4.Size = new Size(40, 20);
            label4.TabIndex = 11;
            label4.Text = "Year:";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(27, 309);
            label5.Name = "label5";
            label5.Size = new Size(44, 20);
            label5.TabIndex = 12;
            label5.Text = "Price:";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(14, 375);
            label6.Name = "label6";
            label6.Size = new Size(57, 20);
            label6.TabIndex = 13;
            label6.Text = "Engine:";
            // 
            // dgv_carList
            // 
            dgv_carList.AllowUserToAddRows = false;
            dgv_carList.AllowUserToDeleteRows = false;
            dgv_carList.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgv_carList.Location = new Point(317, 42);
            dgv_carList.Name = "dgv_carList";
            dgv_carList.ReadOnly = true;
            dgv_carList.RowHeadersWidth = 51;
            dgv_carList.Size = new Size(573, 357);
            dgv_carList.TabIndex = 14;
            dgv_carList.CellContentClick += dgv_carList_CellContentClick;
            // 
            // btn_add
            // 
            btn_add.Location = new Point(103, 446);
            btn_add.Name = "btn_add";
            btn_add.Size = new Size(94, 29);
            btn_add.TabIndex = 15;
            btn_add.Text = "Add";
            btn_add.UseVisualStyleBackColor = true;
            btn_add.Click += btn_add_Click;
            // 
            // btn_remove
            // 
            btn_remove.Location = new Point(313, 446);
            btn_remove.Name = "btn_remove";
            btn_remove.Size = new Size(94, 29);
            btn_remove.TabIndex = 16;
            btn_remove.Text = "Remove";
            btn_remove.UseVisualStyleBackColor = true;
            btn_remove.Click += btn_remove_Click;
            // 
            // btn_clearAll
            // 
            btn_clearAll.Location = new Point(433, 446);
            btn_clearAll.Name = "btn_clearAll";
            btn_clearAll.Size = new Size(94, 29);
            btn_clearAll.TabIndex = 17;
            btn_clearAll.Text = "Clear All";
            btn_clearAll.UseVisualStyleBackColor = true;
            btn_clearAll.Click += btn_clearAll_Click;
            // 
            // btn_orderByName
            // 
            btn_orderByName.Location = new Point(543, 446);
            btn_orderByName.Name = "btn_orderByName";
            btn_orderByName.Size = new Size(118, 29);
            btn_orderByName.TabIndex = 18;
            btn_orderByName.Text = "OrderByName";
            btn_orderByName.UseVisualStyleBackColor = true;
            btn_orderByName.Click += btn_orderByName_Click;
            // 
            // btn_save
            // 
            btn_save.Location = new Point(676, 446);
            btn_save.Name = "btn_save";
            btn_save.Size = new Size(94, 29);
            btn_save.TabIndex = 19;
            btn_save.Text = "Save";
            btn_save.UseVisualStyleBackColor = true;
            btn_save.Click += btn_save_Click;
            // 
            // btn_load
            // 
            btn_load.Location = new Point(796, 446);
            btn_load.Name = "btn_load";
            btn_load.Size = new Size(94, 29);
            btn_load.TabIndex = 20;
            btn_load.Text = "Load";
            btn_load.UseVisualStyleBackColor = true;
            btn_load.Click += btn_load_Click;
            // 
            // numericUpDown_id
            // 
            numericUpDown_id.Location = new Point(92, 45);
            numericUpDown_id.Maximum = new decimal(new int[] { 9999, 0, 0, 0 });
            numericUpDown_id.Name = "numericUpDown_id";
            numericUpDown_id.Size = new Size(150, 27);
            numericUpDown_id.TabIndex = 21;
            // 
            // numericUpDown_price
            // 
            numericUpDown_price.Location = new Point(92, 307);
            numericUpDown_price.Maximum = new decimal(new int[] { 999999999, 0, 0, 0 });
            numericUpDown_price.Name = "numericUpDown_price";
            numericUpDown_price.Size = new Size(150, 27);
            numericUpDown_price.TabIndex = 22;
            // 
            // numericUpDown_year
            // 
            numericUpDown_year.Location = new Point(92, 241);
            numericUpDown_year.Maximum = new decimal(new int[] { 9999, 0, 0, 0 });
            numericUpDown_year.Name = "numericUpDown_year";
            numericUpDown_year.Size = new Size(150, 27);
            numericUpDown_year.TabIndex = 23;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(951, 519);
            Controls.Add(numericUpDown_year);
            Controls.Add(numericUpDown_price);
            Controls.Add(numericUpDown_id);
            Controls.Add(btn_load);
            Controls.Add(btn_save);
            Controls.Add(btn_orderByName);
            Controls.Add(btn_clearAll);
            Controls.Add(btn_remove);
            Controls.Add(btn_add);
            Controls.Add(dgv_carList);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(tBox_engine);
            Controls.Add(tBox_color);
            Controls.Add(tBox_model);
            Name = "Form1";
            Text = "AutoPark";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)dgv_carList).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown_id).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown_price).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown_year).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox tBox_model;
        private TextBox tBox_color;
        private TextBox tBox_engine;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Label label6;
        private DataGridView dgv_carList;
        private Button btn_add;
        private Button btn_remove;
        private Button btn_clearAll;
        private Button btn_orderByName;
        private Button btn_save;
        private Button btn_load;
        private NumericUpDown numericUpDown1;
        private NumericUpDown tbox_Id;
        private NumericUpDown tBox_id;
        private NumericUpDown numericUpDown_id;
        private NumericUpDown numericUpDown_price;
        private NumericUpDown numericUpDown_year;
    }
}
