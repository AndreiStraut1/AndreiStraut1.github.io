using System.ComponentModel;
using System.Windows.Forms;

namespace AutoPark
{
    public partial class Form1 : Form
    {
        private BindingSource _source = new BindingSource();
        CarAgenda agenda = null;
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            agenda = new CarAgenda();

        }

        private void btn_add_Click(object sender, EventArgs e)
        {
            Car car = new Car();
            if (string.IsNullOrEmpty(tBox_model.Text) || string.IsNullOrEmpty(tBox_color.Text) || numericUpDown_price.Value < 0 || string.IsNullOrEmpty(tBox_engine.Text))
            {
                MessageBox.Show("All fields need to be filled!");
                return;
            }
            if (numericUpDown_year.Value < 1886)
            {
                MessageBox.Show("Cars were not invented back then");
                return;
            }
            car.Id = dgv_carList.RowCount + 1;
            car.Model = tBox_model.Text;
            car.Color = tBox_color.Text;
            car.Year = (int)numericUpDown_year.Value;
            car.Price = (int)numericUpDown_price.Value;
            car.Engine = tBox_engine.Text;

            agenda.Add(car);
            _source.DataSource = agenda.Cars.OrderBy(x => x.Id).ToList();
            dgv_carList.DataSource = _source;
            
            ClearFormContent();


        }

        private void ClearFormContent()
        {
            numericUpDown_id.Value = 0;
            tBox_model.Clear();
            tBox_color.Clear();
            numericUpDown_year.Value = 0;
            numericUpDown_price.Value = 0;
            tBox_engine.Clear();
        }

        private void dgv_carList_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                numericUpDown_id.Value = (int)dgv_carList.Rows[e.RowIndex].Cells[0].Value;
                tBox_model.Text = dgv_carList.Rows[e.RowIndex].Cells[1].Value.ToString();
                tBox_color.Text = dgv_carList.Rows[e.RowIndex].Cells[2].Value.ToString();
                numericUpDown_year.Value = (int)dgv_carList.Rows[e.RowIndex].Cells[3].Value;
                numericUpDown_price.Value = (int)dgv_carList.Rows[e.RowIndex].Cells[4].Value;
                tBox_engine.Text = dgv_carList.Rows[e.RowIndex].Cells[5].Value.ToString();
            }
        }

        private void tBox_id_TextChanged(object sender, EventArgs e)
        {

        }

        private void btn_remove_Click(object sender, EventArgs e)
        {
            Car car = new Car();
            foreach (DataGridViewRow dgv_row in dgv_carList.SelectedRows)
            {
                if (dgv_row != null)
                {
                    car = dgv_row.DataBoundItem as Car;
                    int temp = car.Id;
                    agenda.Remove(car);
                    dgv_carList.Rows.Remove(dgv_row);
                    for (int i = temp; i <= dgv_carList.RowCount; i++)
                        agenda.Cars[i-1].Id--;
                    dgv_carList.Refresh();
                }
            }
            
            dgv_carList.Refresh();

        }

        private void btn_clearAll_Click(object sender, EventArgs e)
        {
            agenda.Cars.Clear();
            dgv_carList.Rows.Clear();
            dgv_carList.Refresh();
        }

        private void btn_orderByName_Click(object sender, EventArgs e)
        {
            if (btn_orderByName.Text == "OrderByName")
            {
                btn_orderByName.Text = "OrderById";
                _source.DataSource = agenda.Cars.OrderBy(x => x.Model).ToList();
                dgv_carList.Refresh();
            }
            else if(btn_orderByName.Text == "OrderById")
            {
                btn_orderByName.Text = "OrderByName";
                _source.DataSource = agenda.Cars.OrderBy(x => x.Id).ToList();
                dgv_carList.Refresh();
            }
        }

        private void btn_save_Click(object sender, EventArgs e)
        {
            agenda.SaveOnDisk();
        }

        private void btn_load_Click(object sender, EventArgs e)
        {
            agenda.LoadFromDisk();
            _source.DataSource = agenda.Cars.ToList();
            dgv_carList.DataSource = _source;
            dgv_carList.Refresh();
        }
    }
}
