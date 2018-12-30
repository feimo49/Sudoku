using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;
using System.IO;
#region System.Windows.Forms.Timer

namespace Sudoku_GUI
{
    public partial class Form1 : Form
    {
        public static ArrayList tbxList = new ArrayList();
        public static int flag = 0;
        public Form1()
        {
            InitializeComponent();
        }
     

        //定义Timer 
        System.Timers.Timer Mytimer;
        long TimeCount;
        public delegate void SetControlValue(long value);

        private void Exit_Click(object sender, EventArgs e)
        {
            if (DialogResult.Yes == MessageBox.Show("确认退出？", "提示", MessageBoxButtons.YesNo, MessageBoxIcon.Information))
                Application.Exit();
        }

        private void Form1_Load(object sender, EventArgs e)
        {   
            tbxList.Add(tbx11);
            tbxList.Add(tbx12);
            tbxList.Add(tbx13);
            tbxList.Add(tbx14);
            tbxList.Add(tbx15);
            tbxList.Add(tbx16);
            tbxList.Add(tbx17);
            tbxList.Add(tbx18);
            tbxList.Add(tbx19);

            tbxList.Add(tbx21);
            tbxList.Add(tbx22);
            tbxList.Add(tbx23);
            tbxList.Add(tbx24);
            tbxList.Add(tbx25);
            tbxList.Add(tbx26);
            tbxList.Add(tbx27);
            tbxList.Add(tbx28);
            tbxList.Add(tbx29);

            tbxList.Add(tbx31);
            tbxList.Add(tbx32);
            tbxList.Add(tbx33);
            tbxList.Add(tbx34);
            tbxList.Add(tbx35);
            tbxList.Add(tbx36);
            tbxList.Add(tbx37);
            tbxList.Add(tbx38);
            tbxList.Add(tbx39);

            tbxList.Add(tbx41);
            tbxList.Add(tbx42);
            tbxList.Add(tbx43);
            tbxList.Add(tbx44);
            tbxList.Add(tbx45);
            tbxList.Add(tbx46);
            tbxList.Add(tbx47);
            tbxList.Add(tbx48);
            tbxList.Add(tbx49);

            tbxList.Add(tbx51);
            tbxList.Add(tbx52);
            tbxList.Add(tbx53);
            tbxList.Add(tbx54);
            tbxList.Add(tbx55);
            tbxList.Add(tbx56);
            tbxList.Add(tbx57);
            tbxList.Add(tbx58);
            tbxList.Add(tbx59);

            tbxList.Add(tbx61);
            tbxList.Add(tbx62);
            tbxList.Add(tbx63);
            tbxList.Add(tbx64);
            tbxList.Add(tbx65);
            tbxList.Add(tbx66);
            tbxList.Add(tbx67);
            tbxList.Add(tbx68);
            tbxList.Add(tbx69);

            tbxList.Add(tbx71);
            tbxList.Add(tbx72);
            tbxList.Add(tbx73);
            tbxList.Add(tbx74);
            tbxList.Add(tbx75);
            tbxList.Add(tbx76);
            tbxList.Add(tbx77);
            tbxList.Add(tbx78);
            tbxList.Add(tbx79);

            tbxList.Add(tbx81);
            tbxList.Add(tbx82);
            tbxList.Add(tbx83);
            tbxList.Add(tbx84);
            tbxList.Add(tbx85);
            tbxList.Add(tbx86);
            tbxList.Add(tbx87);
            tbxList.Add(tbx88);
            tbxList.Add(tbx89);

            tbxList.Add(tbx91);
            tbxList.Add(tbx92);
            tbxList.Add(tbx93);
            tbxList.Add(tbx94);
            tbxList.Add(tbx95);
            tbxList.Add(tbx96);
            tbxList.Add(tbx97);
            tbxList.Add(tbx98);
            tbxList.Add(tbx99);

            int interval = 1000;
            Mytimer = new System.Timers.Timer(interval);
            Mytimer.AutoReset = true;
            Mytimer.Elapsed += new System.Timers.ElapsedEventHandler(Mytimer_tick);

        }

        private void Mytimer_tick(object sender, System.Timers.ElapsedEventArgs e)
        {
            this.Invoke(new SetControlValue(ShowTime), TimeCount);
            TimeCount++;
        }

        private void ShowTime(long t)
        {
            TimeSpan temp = new TimeSpan(0, 0, (int)t);
            label1.Text = string.Format(" TIME:\n\n{0:00}:{1:00}:{2:00}", temp.Hours, temp.Minutes, temp.Seconds);
        }

        private void Submit_Click(object sender, EventArgs e)
        {
            //停止执行
            Mytimer.Stop();
            string[] submap;
            submap = new string[10];
            for(int i=0;i<9;i++)
            {
                submap[i] = "";
                for(int j=0;j<9;j++)
                {
                    TextBox tbx = tbxList[i * 9 + j] as TextBox;
                    if(tbx.Text=="")
                    {
                        MessageBox.Show("未完成", "提示");
                        return;
                    }
                    submap[i] += tbx.Text;
                }
            }

            int[] row = { 0, 3, 6, 27, 30, 33, 54, 57, 60 };
            int[] add = { 0, 1, 2, 9, 10, 11, 18, 19, 20 };
            //检查答案是否正确
            for (int i=0; i < 9;i++)
            {
                int[] count_r = new int[10];//一行中每个数字出现的次数
                int[] count_c = new int[10];//一列中每个数字出现的个数
                int[] count_g = new int[10];//一个小九宫格中每个数字出现的个数
                //计数清零
                for (int j=0;j<9;j++)
                {
                    count_r[j] = 0;
                    count_c[j] = 0;
                    count_g[j] = 0;
                }
                //计数
                for(int j=0;j<9;j++)
                {
                    count_r[submap[i][j]-'0']++;
                    count_c[submap[j][i]-'0']++;

                    int pos = row[i] + add[j];
                    int m = pos / 9;
                    int n = pos % 9;
                    count_g[submap[m][n]-'0']++;
                }

                for(int j=1;j<9;j++)
                {
                    if (count_r[j]==0 || count_r[j] > 1||count_c[j]==0||count_c[j]>1||count_g[j]==0||count_g[j]>1)
                    {
                        MessageBox.Show("回答错误！", "提示");
                        return;
                    }
                }
            }
            MessageBox.Show("Bingo~", "通过提示");
        }

        private void Next_Click(object sender, EventArgs e)
        {
            StreamReader sr1 = new StreamReader(@"sudo.txt");
            for(int k=0;k<10*flag;k++)
            {
                string lines = sr1.ReadLine();
            }
            for(int i=0;i<9;i++)
            {
                string line = sr1.ReadLine();
                for(int j=0;j<9;j++)
                {
                    TextBox tbx = tbxList[i * 9 + j] as TextBox;
                    if(line[2*j]=='0')
                    {
                        tbx.Text = "";
                        tbx.ReadOnly = false;
                        tbx.ForeColor = Color.Black;
                        tbx.BackColor = Color.Ivory;
                    }
                    else
                    {
                        tbx.Text = line[2 * j].ToString();
                        tbx.ReadOnly = true;
                        tbx.ForeColor = Color.Brown;
                        tbx.BackColor = Color.MistyRose;
                    }
                }
            }
            flag++;

            //手动设置Timer，开始执行 
            Mytimer.Start();
            TimeCount = 0;
        }

        private void Reset_Click(object sender, EventArgs e)
        {
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    TextBox tbx = tbxList[i * 9 + j] as TextBox;
                    if (tbx.ReadOnly==false)
                        tbx.Text = "";
                }
            }
            //停止执行 
            Mytimer.Stop();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            
        }
    }
}
#endregion