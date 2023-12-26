using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shaikhutdinov_lr6
{
    public partial class Form2 : Form
    {
        public Form1 main;
        public ListBox list;
        Car car;
        public bool onEdit;
        public int setter;
        public Form2(Form1 form, ListBox list, ref Car car, bool onEdit, int setter)
        {
            this.setter = setter;
            this.onEdit = onEdit;
            this.main = form;
            this.list = list;
            InitializeComponent();
            textBoxMake.Text = car.make.ToString();
            textBoxModel.Text = car.model.ToString();
            textBoxPower.Text = car.power.ToString();
            textBoxEC.Text = car.engine_capacity.ToString();
            textBoxPY.Text = car.production_year.ToString();
            if (car.number_of_owners != 0)
            {
                textBoxNO.Text = car.number_of_owners.ToString();
                textBoxMileage.Text = car.mileage.ToString();
                labelNO.Visible = true;
                labelMileage.Visible = true;
            }
            else
            {
                textBoxNO.Visible = false;
                textBoxMileage.Visible = false;
                labelNO.Visible = true;
                labelMileage.Visible = true;
            }
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            bool flag = true;
            try
            {
                car.make = textBoxMake.Text;
                car.model = textBoxModel.Text;
                car.power = int.TryParse(textBoxPower.Text, out car.power) ? car.power : -1;
                car.production_year = int.TryParse(textBoxPY.Text, out car.production_year) ? car.production_year : -1;
                car.engine_capacity = float.TryParse(textBoxEC.Text, out car.engine_capacity) ? car.engine_capacity : -1;
                if (textBoxNO.Visible && textBoxMileage.Visible)
                {
                    car.number_of_owners = int.TryParse(textBoxNO.Text, out car.number_of_owners) ? car.number_of_owners : -1;
                    car.mileage = float.TryParse(textBoxMileage.Text, out car.mileage) ? car.mileage : -1;
                }
            }
            catch (Exception)
            {
                flag = false;
            }
            if (car.make == "" || car.model == "" || car.power < 10 || car.production_year < 1900 || car.production_year > 2023 || car.engine_capacity < 1)
            {
                flag = false;
            }
            if (textBoxNO.Visible && textBoxMileage.Visible)
            {
                if (car.number_of_owners < 1 || car.mileage < 1)
                {
                    flag = false;
                }
            }
            if (flag && !onEdit)
            {
                main.Add(ref car);
            }
            else if (!flag)
            {
                MessageBox.Show(
                    "Неверный ввод",
                    "Неверный ввод",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Information,
                    MessageBoxDefaultButton.Button1,
                    MessageBoxOptions.DefaultDesktopOnly);            
            }
            else if (flag && onEdit)
            {
                main.EditSelected(ref car, this.setter);
            }
            main.Cancel();
            this.Close();
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            main.Cancel();
            this.Close();
        }
    }
}
