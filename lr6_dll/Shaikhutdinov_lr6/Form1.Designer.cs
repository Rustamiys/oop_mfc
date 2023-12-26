namespace Shaikhutdinov_lr6
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonClear = new System.Windows.Forms.Button();
            this.buttonAddUC = new System.Windows.Forms.Button();
            this.buttonAddNC = new System.Windows.Forms.Button();
            this.buttonSave = new System.Windows.Forms.Button();
            this.buttonLoad = new System.Windows.Forms.Button();
            this.buttonEdit = new System.Windows.Forms.Button();
            this.textBoxMileage = new System.Windows.Forms.TextBox();
            this.labelMileage = new System.Windows.Forms.Label();
            this.buttonDelete = new System.Windows.Forms.Button();
            this.textBoxNO = new System.Windows.Forms.TextBox();
            this.labelNO = new System.Windows.Forms.Label();
            this.textBoxPY = new System.Windows.Forms.TextBox();
            this.labelPY = new System.Windows.Forms.Label();
            this.textBoxEC = new System.Windows.Forms.TextBox();
            this.labelEC = new System.Windows.Forms.Label();
            this.textBoxPower = new System.Windows.Forms.TextBox();
            this.labelPower = new System.Windows.Forms.Label();
            this.textBoxModel = new System.Windows.Forms.TextBox();
            this.labelModel = new System.Windows.Forms.Label();
            this.textBoxMake = new System.Windows.Forms.TextBox();
            this.labelMake = new System.Windows.Forms.Label();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.SuspendLayout();
            // 
            // buttonClear
            // 
            this.buttonClear.Location = new System.Drawing.Point(800, 598);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(165, 48);
            this.buttonClear.TabIndex = 46;
            this.buttonClear.Text = "Очистить";
            this.buttonClear.UseVisualStyleBackColor = true;
            this.buttonClear.Click += new System.EventHandler(this.buttonClear_Click);
            // 
            // buttonAddUC
            // 
            this.buttonAddUC.Location = new System.Drawing.Point(500, 598);
            this.buttonAddUC.Name = "buttonAddUC";
            this.buttonAddUC.Size = new System.Drawing.Size(247, 48);
            this.buttonAddUC.TabIndex = 45;
            this.buttonAddUC.Text = "Добавить б/у машину";
            this.buttonAddUC.UseVisualStyleBackColor = true;
            this.buttonAddUC.Click += new System.EventHandler(this.buttonAddUC_Click);
            // 
            // buttonAddNC
            // 
            this.buttonAddNC.Location = new System.Drawing.Point(208, 598);
            this.buttonAddNC.Name = "buttonAddNC";
            this.buttonAddNC.Size = new System.Drawing.Size(253, 48);
            this.buttonAddNC.TabIndex = 44;
            this.buttonAddNC.Text = "Добавить новую машину";
            this.buttonAddNC.UseVisualStyleBackColor = true;
            this.buttonAddNC.Click += new System.EventHandler(this.buttonAddNC_Click);
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(585, 534);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(380, 48);
            this.buttonSave.TabIndex = 43;
            this.buttonSave.Text = "Сохранить в файл";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // buttonLoad
            // 
            this.buttonLoad.Location = new System.Drawing.Point(585, 477);
            this.buttonLoad.Name = "buttonLoad";
            this.buttonLoad.Size = new System.Drawing.Size(380, 51);
            this.buttonLoad.TabIndex = 42;
            this.buttonLoad.Text = "Считать из файла";
            this.buttonLoad.UseVisualStyleBackColor = true;
            this.buttonLoad.Click += new System.EventHandler(this.buttonLoad_Click);
            // 
            // buttonEdit
            // 
            this.buttonEdit.Location = new System.Drawing.Point(585, 421);
            this.buttonEdit.Name = "buttonEdit";
            this.buttonEdit.Size = new System.Drawing.Size(380, 50);
            this.buttonEdit.TabIndex = 41;
            this.buttonEdit.Text = "Редактировать";
            this.buttonEdit.UseVisualStyleBackColor = true;
            this.buttonEdit.Click += new System.EventHandler(this.buttonEdit_Click);
            // 
            // textBoxMileage
            // 
            this.textBoxMileage.Location = new System.Drawing.Point(585, 389);
            this.textBoxMileage.Name = "textBoxMileage";
            this.textBoxMileage.Size = new System.Drawing.Size(380, 26);
            this.textBoxMileage.TabIndex = 40;
            // 
            // labelMileage
            // 
            this.labelMileage.AutoSize = true;
            this.labelMileage.Location = new System.Drawing.Point(589, 366);
            this.labelMileage.Name = "labelMileage";
            this.labelMileage.Size = new System.Drawing.Size(93, 20);
            this.labelMileage.TabIndex = 39;
            this.labelMileage.Text = "Пробег(км)";
            // 
            // buttonDelete
            // 
            this.buttonDelete.Location = new System.Drawing.Point(22, 598);
            this.buttonDelete.Name = "buttonDelete";
            this.buttonDelete.Size = new System.Drawing.Size(133, 48);
            this.buttonDelete.TabIndex = 38;
            this.buttonDelete.Text = "Удалить";
            this.buttonDelete.UseVisualStyleBackColor = true;
            this.buttonDelete.Click += new System.EventHandler(this.buttonDelete_Click);
            // 
            // textBoxNO
            // 
            this.textBoxNO.Location = new System.Drawing.Point(585, 328);
            this.textBoxNO.Name = "textBoxNO";
            this.textBoxNO.Size = new System.Drawing.Size(380, 26);
            this.textBoxNO.TabIndex = 37;
            // 
            // labelNO
            // 
            this.labelNO.AutoSize = true;
            this.labelNO.Location = new System.Drawing.Point(590, 291);
            this.labelNO.Name = "labelNO";
            this.labelNO.Size = new System.Drawing.Size(198, 20);
            this.labelNO.TabIndex = 36;
            this.labelNO.Text = "Количество владельцев";
            // 
            // textBoxPY
            // 
            this.textBoxPY.Location = new System.Drawing.Point(585, 260);
            this.textBoxPY.Name = "textBoxPY";
            this.textBoxPY.Size = new System.Drawing.Size(380, 26);
            this.textBoxPY.TabIndex = 35;
            // 
            // labelPY
            // 
            this.labelPY.AutoSize = true;
            this.labelPY.Location = new System.Drawing.Point(590, 236);
            this.labelPY.Name = "labelPY";
            this.labelPY.Size = new System.Drawing.Size(103, 20);
            this.labelPY.TabIndex = 34;
            this.labelPY.Text = "Год выпуска";
            // 
            // textBoxEC
            // 
            this.textBoxEC.Location = new System.Drawing.Point(585, 205);
            this.textBoxEC.Name = "textBoxEC";
            this.textBoxEC.Size = new System.Drawing.Size(380, 26);
            this.textBoxEC.TabIndex = 33;
            // 
            // labelEC
            // 
            this.labelEC.AutoSize = true;
            this.labelEC.Location = new System.Drawing.Point(589, 180);
            this.labelEC.Name = "labelEC";
            this.labelEC.Size = new System.Drawing.Size(167, 20);
            this.labelEC.TabIndex = 32;
            this.labelEC.Text = "Объем двигателя(л)";
            // 
            // textBoxPower
            // 
            this.textBoxPower.Location = new System.Drawing.Point(585, 146);
            this.textBoxPower.Name = "textBoxPower";
            this.textBoxPower.Size = new System.Drawing.Size(380, 26);
            this.textBoxPower.TabIndex = 31;
            // 
            // labelPower
            // 
            this.labelPower.AutoSize = true;
            this.labelPower.Location = new System.Drawing.Point(590, 122);
            this.labelPower.Name = "labelPower";
            this.labelPower.Size = new System.Drawing.Size(124, 20);
            this.labelPower.TabIndex = 30;
            this.labelPower.Text = "Мощность(л.с.)";
            // 
            // textBoxModel
            // 
            this.textBoxModel.Location = new System.Drawing.Point(585, 89);
            this.textBoxModel.Name = "textBoxModel";
            this.textBoxModel.Size = new System.Drawing.Size(380, 26);
            this.textBoxModel.TabIndex = 29;
            // 
            // labelModel
            // 
            this.labelModel.AutoSize = true;
            this.labelModel.Location = new System.Drawing.Point(590, 65);
            this.labelModel.Name = "labelModel";
            this.labelModel.Size = new System.Drawing.Size(70, 20);
            this.labelModel.TabIndex = 28;
            this.labelModel.Text = "Модель";
            // 
            // textBoxMake
            // 
            this.textBoxMake.Location = new System.Drawing.Point(585, 33);
            this.textBoxMake.Name = "textBoxMake";
            this.textBoxMake.Size = new System.Drawing.Size(380, 26);
            this.textBoxMake.TabIndex = 27;
            // 
            // labelMake
            // 
            this.labelMake.AutoSize = true;
            this.labelMake.Location = new System.Drawing.Point(590, 9);
            this.labelMake.Name = "labelMake";
            this.labelMake.Size = new System.Drawing.Size(57, 20);
            this.labelMake.TabIndex = 26;
            this.labelMake.Text = "Марка";
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 20;
            this.listBox1.Location = new System.Drawing.Point(22, 18);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(509, 564);
            this.listBox1.TabIndex = 25;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(988, 664);
            this.Controls.Add(this.buttonClear);
            this.Controls.Add(this.buttonAddUC);
            this.Controls.Add(this.buttonAddNC);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.buttonLoad);
            this.Controls.Add(this.buttonEdit);
            this.Controls.Add(this.textBoxMileage);
            this.Controls.Add(this.labelMileage);
            this.Controls.Add(this.buttonDelete);
            this.Controls.Add(this.textBoxNO);
            this.Controls.Add(this.labelNO);
            this.Controls.Add(this.textBoxPY);
            this.Controls.Add(this.labelPY);
            this.Controls.Add(this.textBoxEC);
            this.Controls.Add(this.labelEC);
            this.Controls.Add(this.textBoxPower);
            this.Controls.Add(this.labelPower);
            this.Controls.Add(this.textBoxModel);
            this.Controls.Add(this.labelModel);
            this.Controls.Add(this.textBoxMake);
            this.Controls.Add(this.labelMake);
            this.Controls.Add(this.listBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonClear;
        private System.Windows.Forms.Button buttonAddUC;
        private System.Windows.Forms.Button buttonAddNC;
        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.Button buttonLoad;
        private System.Windows.Forms.Button buttonEdit;
        private System.Windows.Forms.TextBox textBoxMileage;
        private System.Windows.Forms.Label labelMileage;
        private System.Windows.Forms.Button buttonDelete;
        private System.Windows.Forms.TextBox textBoxNO;
        private System.Windows.Forms.Label labelNO;
        private System.Windows.Forms.TextBox textBoxPY;
        private System.Windows.Forms.Label labelPY;
        private System.Windows.Forms.TextBox textBoxEC;
        private System.Windows.Forms.Label labelEC;
        private System.Windows.Forms.TextBox textBoxPower;
        private System.Windows.Forms.Label labelPower;
        private System.Windows.Forms.TextBox textBoxModel;
        private System.Windows.Forms.Label labelModel;
        private System.Windows.Forms.TextBox textBoxMake;
        private System.Windows.Forms.Label labelMake;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
    }
}

