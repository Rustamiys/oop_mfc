using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shaikhutdinov_lr6
{
    public struct Car
    {

        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 256)]
        public string make;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 256)]
        public string model;
        [MarshalAs(UnmanagedType.I4)]
        public int power;
        [MarshalAs(UnmanagedType.R4)]
        public float engine_capacity;
        [MarshalAs(UnmanagedType.I4)]
        public int production_year;
        [MarshalAs(UnmanagedType.I4)]
        public int number_of_owners;
        [MarshalAs(UnmanagedType.R4)]
        public float mileage;
    };
    public partial class Form1 : Form
    {
        [DllImport(@"..\Shaikhutdinov_lr6\x64\Debug\MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern bool WarehouseLoad(StringBuilder filename);
        [DllImport(@"..\Shaikhutdinov_lr6\x64\Debug\MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern bool WarehouseSave(StringBuilder filename);
        [DllImport(@"..\Shaikhutdinov_lr6\x64\Debug\MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void WarehouseDeleteCar(int id);
        [DllImport(@"..\Shaikhutdinov_lr6\x64\Debug\MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void WarehouseUpdateCar(ref Car car, int id);
        [DllImport(@"..\Shaikhutdinov_lr6\x64\Debug\MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void WarehouseClear();
        [DllImport(@"..\Shaikhutdinov_lr6\x64\Debug\MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void WarehouseAddCar(ref Car car);
        [DllImport(@"..\Shaikhutdinov_lr6\x64\Debug\MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void WarehouseInsertCar(ref Car car, int id);
        [DllImport(@"..\Shaikhutdinov_lr6\x64\Debug\MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern void WarehouseGetCar(ref Car car, int id);
        [DllImport(@"..\Shaikhutdinov_lr6\x64\Debug\MFCLibrary1.dll", CharSet = CharSet.Ansi)]
        private static extern int WarehouseSize();
        public void VizView(bool newCar, bool usedCar)
        {
            if (newCar)
            {
                textBoxMake.Visible = true;
                textBoxModel.Visible = true;
                textBoxPower.Visible = true;
                textBoxEC.Visible = true;
                textBoxPY.Visible = true;
                labelMake.Visible = true;
                labelModel.Visible = true;
                labelPower.Visible = true;
                labelEC.Visible = true;
                labelPY.Visible = true;
            }
            else
            {
                textBoxMake.Visible = false;
                textBoxModel.Visible = false;
                textBoxPower.Visible = false;
                textBoxEC.Visible = false;
                textBoxPY.Visible = false;
                labelMake.Visible = false;
                labelModel.Visible = false;
                labelPower.Visible = false;
                labelEC.Visible = false;
                labelPY.Visible = false;
            }
            if (usedCar)
            {
                textBoxNO.Visible = true;
                textBoxMileage.Visible = true;
                labelNO.Visible = true;
                labelMileage.Visible = true;
            }
            else
            {
                textBoxNO.Visible = false;
                textBoxMileage.Visible = false;
                labelNO.Visible = false;
                labelMileage.Visible = false;
            }
        }
        public Form1()
        {
            InitializeComponent();
            VizView(false, false);
        }
        Car car;
        public void Cancel()
        {
            ListBoxUpdate();
        }
        public void Add(ref Car car)
        {
            WarehouseAddCar(ref car);
            ListBoxUpdate();
        }
        public void EditSelected(ref Car car, int id)
        {
            WarehouseInsertCar(ref car, id);
            ListBoxUpdate();
            listBox1.SetSelected(id, true);
        }
        private void ListBoxUpdate()
        {
            VizView(false, false);
            listBox1.Items.Clear();
            int q = WarehouseSize();
            for (int i = 0; i < q; i++)
            {
                WarehouseGetCar(ref car, i);
                listBox1.Items.Add(car.model + " " + car.make);
                listBox1.SetSelected(i, true);
            }
        }
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex < 0)
                return;
            if (listBox1.Items.Count != WarehouseSize())
            {
                return;
            }
            WarehouseGetCar(ref car, listBox1.SelectedIndex);
            VizView(true, false);    
            if (car.number_of_owners != 0)
            {
                VizView(true, true);
                textBoxNO.Text = car.number_of_owners.ToString();
                textBoxMileage.Text = car.mileage.ToString();
            }
            else
            {
                textBoxNO.Text = "0";
                textBoxMileage.Text = "0";
            }
            textBoxMake.Text = car.make.ToString();
            textBoxModel.Text = car.model.ToString();
            textBoxPower.Text = car.power.ToString();
            textBoxEC.Text = car.engine_capacity.ToString();
            textBoxPY.Text = car.production_year.ToString();
        }

        private void buttonEdit_Click(object sender, EventArgs e)
        {
            if (listBox1.Items.Count == 0)
            {
                return;
            }
            car.make = textBoxMake.Text;
            car.model = textBoxModel.Text;
            car.power = Int32.Parse(textBoxPower.Text);
            car.engine_capacity = float.Parse(textBoxEC.Text);
            car.power = Int32.Parse(textBoxPower.Text);
            car.number_of_owners = int.TryParse(textBoxNO.Text, out car.number_of_owners) ? car.number_of_owners : 0;
            car.mileage = float.TryParse(textBoxMileage.Text, out car.mileage) ? car.mileage : 0;
            Form2 Form2 = new Form2(this, this.listBox1, ref car, true, listBox1.SelectedIndex);
            Form2.Show();
         
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex < 0)
                return;
            WarehouseDeleteCar(listBox1.SelectedIndex);
            ListBoxUpdate();
        }

        private void buttonLoad_Click(object sender, EventArgs e)
        {
            WarehouseClear();
            listBox1.Items.Clear();
            openFileDialog1.InitialDirectory = Directory.GetCurrentDirectory();
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                var FileName = new StringBuilder(openFileDialog1.FileName);
                WarehouseLoad(FileName);

                int loaded_size = WarehouseSize();
                for (int i = 0; i < loaded_size; ++i)
                {
                    WarehouseGetCar(ref car, i);
                }
                ListBoxUpdate();
            }
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            saveFileDialog1.InitialDirectory = Directory.GetCurrentDirectory();
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                var filepath = new StringBuilder(saveFileDialog1.FileName);
                WarehouseSave(filepath);
            }
        }

        private void buttonAddNC_Click(object sender, EventArgs e)
        {
            car.make = ""; car.model = "";
            car.power = 0; car.engine_capacity = 0;
            car.mileage = -1; car.production_year = 0; car.number_of_owners = 0;
            Form2 Form2 = new Form2(this, this.listBox1, ref car, false, listBox1.SelectedIndex);
            Form2.Show();
        }

        private void buttonAddUC_Click(object sender, EventArgs e)
        {
            car.make = ""; car.model = "";
            car.power = 0; car.engine_capacity = 0;
            car.mileage = 0; car.production_year = 0; car.number_of_owners = 1;
            Form2 Form2 = new Form2(this, this.listBox1, ref car, false, listBox1.SelectedIndex);
            Form2.Show();
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            WarehouseClear();
            ListBoxUpdate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }


    }
}
