/*
 *遗传算法
 *
 *作者 郑艺林 李子强 周宸宇
 *
 *请按照交互信息提示一次输入文件路径（全路径）、必经点、必经边、基因个体数、最大运行时间（以 s 计时）、变异率
 *PS：windows 下如果 30 行报错，请把 string 改成 char* 并用路径字符串替换 126 的 input_file
 * 本例 0 表示 S, 17 表示 E
 *本代码发布于 GPL v2
 */

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <algorithm>
#include <utility>
using namespace std;

typedef struct Gene{
    int score;
    vector<int> gene_data;
    int distance;
}gene; //基因个体

string input_file;
fstream fh;
vector<vector<int> > map; // 图
int len; // 基因长度
vector<gene>  genes; //染色体组
vector<int> points; //点集
vector<int> mP; //必经点
vector<pair<int,int> > mE; //必经路径
int child_count = 200; //子代数目
int max_time = 60; //秒
const float reserve_rate = 0.5; //存活率
const float death_rate = 0.5; //死亡率
float mut_rate = 0.6; //变异率


vector<int> gen_gene(int size);//生成下一代
int cal_score(vector<int> gene_data);//计算适应度
int cal_distance(vector<int> a);//计算路程
bool compDistance(const gene &a, const gene &b);//比较路程长度
vector<int> crossover(vector<int> &a, vector<int> &b, float mut_rate);//变异交叉互换

int main(void)
{
    //交互提示
    int temp;
    float temp_f;
    int tmp_p;
    cout<<"Input the test file : ";
    cin>>input_file;
    
    cout<<"Input the Necessary point(enter -1 to end): ";
     while(1)
     {
         cin>>tmp_p;
         if(tmp_p == -1)
         {
             break;
         }
         mP.push_back(tmp_p);
     }
//    mP.push_back(7); //测试代码
//    mP.push_back(12);
    cout<<"Input the ends of necessary edge (enter -1 to end): ";
     while(1)
     {
         pair<int, int> tmp;
         cin>>tmp.first;
         if(tmp.first == -1)
         {
             break;
         }
         cin>>tmp.second;
         mE.push_back(tmp);
     }
//    mE.push_back(make_pair(2,4));
//    mE.push_back(make_pair(13,14));
    
    cout<<"Input the gene amount (enter 0 to set default 200) : ";
    temp = 0;
    cin>>temp;
    if(temp > 0)
    {
        child_count = temp;
    }
    else if(temp < 0)
    {
        cerr<<"wrong number!!"<<endl;;
        exit(1);
    }
    
    cout<<"Input the max time (s) (enter 0 to set default 60 second) : ";
    temp = 0;
    cin>>temp;
    if(temp > 0)
    {
        max_time = temp;
    }
    else if(temp < 0)
    {
        cout<<"Wrong number!!"<<endl;
        exit(1);
    }
    
    cout<<"Input the mutation rate (0.0, 1.0] (enter 0 to set default 0.6) : ";
    temp_f = 0;
    cin>>temp_f;
    if(temp_f <= 1 && temp_f > 0)
    {
        mut_rate = temp_f;
    }
    else if(temp_f < 0)
    {
        cerr<<"Wrong number!!"<<endl;
        exit(1);
    }
    cout<<"Running..."<<endl;
    fh.open(input_file, ios::in);
    if(fh.fail())
    {
        cerr<<"Failed to open file"<<input_file<<endl;
        exit(1);
    }
    string length;
    getline(fh, length);
    len = atoi(length.c_str());
    for(int i = 0;i<len;++i)
    {
        points.push_back(i);
    } //建立点集合
    string line;
    while(!fh.eof())
    {
        getline(fh, line);
        char comma;
        vector<int> point;
        if(line == "\0")
        {
            continue;
        }
        for(int i = 0; i< line.size();++i)
        {
            line += ",";
            comma = line.find(',', i);
            int p = atoi(line.substr(i,comma-i).c_str()); //定位到合适的位置转化子串为数值并存储
            point.push_back(p);
            i = comma;
        }
        map.push_back(point);
    } //读取文件生成邻接矩阵
    
    // for(int i = 0;i<len;++i)
    // {
    //     for(int j = 0;j<len;++j)
    //     {
    //         cout<<map[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }//输出图信息
    
    srand((int)time(NULL));
    int start_time = (int)time(NULL);
    for(int i = 0;i<child_count;++i)
    {
        gene g;
        g.distance = 0;
        g.gene_data = gen_gene(len);
        g.score = cal_score(g.gene_data);
        
        if(g.score != mP.size()+mE.size())
        {
            --i;
            continue;
        }
        genes.push_back(g);
    }
    
    int g = 1; //初始代数为 1
    int reserve_limit, death_limit;
    vector<int> father, mother;  //双亲
    vector<gene> next_gen; //下一代
    reserve_limit = child_count * reserve_rate;
    death_limit = child_count * (1 - death_rate);
    while(1)
    {
        for(int i = 0;i<genes.size();++i)
        {
            genes[i].distance = cal_distance(genes[i].gene_data);
        }
        sort(genes.begin(), genes.end(), compDistance);
//        for(int i = 0;i<genes.size();++i)
//        {
//             for(int j = 0;j < genes[i].gene_data.size();++j)
//             {
//                 cout<<genes[i].gene_data[j]<<" ";
//             }
//             cout<<"distance is "<<genes[i].distance<<endl; //输出基因组信息，路径长度
//        }
        if(time(NULL) - start_time >= max_time)
        {
            break; //到达运行时间，停止进化
        }
        
        for(int i = 0; i < child_count; ++i)
        {
            if(i >= death_limit)
            {
                gene g;
                g.distance = 0;
                g.score = 0;
                while(g.score != mP.size()+mE.size())
                {   //不符合适应度要求，则重新产生
                    g.gene_data = gen_gene(len);
                    g.score = cal_score(g.gene_data);
                }
                next_gen.push_back(g);
            }
            else if(i <= reserve_limit)
            {   //小于存活数量，则产生新个体
                next_gen.push_back(genes[i]);
            }
            else
            {
                father = genes[rand()%reserve_limit].gene_data;
                mother = genes[rand()%child_count].gene_data;
                gene g;
                g.distance = 0;
                g.score = 0;
                while(g.score != mP.size()+mE.size())
                {
                    g.gene_data = crossover(father, mother, mut_rate);
                    g.score = cal_score(g.gene_data);
                }
                next_gen.push_back(g);
            }
            
        }
        genes = next_gen; //存储下一代
        ++g;
    }
    
    fh.close(); //关闭文件流
    //输出结果
    cout<<"After "<<g<<" generations"<<endl;
    cout<<"Distance:"<<genes[0].distance<<endl;
    cout<<"Path : ";
    int i = 0;
    for(;i<genes[0].gene_data.size()-1;++i)
    {
        cout<<genes[0].gene_data[i]<<"->";
    }
    cout<<genes[0].gene_data[i]<<endl;
    return 0;
}

//生成下一代
vector<int> gen_gene(int size)
{
    vector<int> gene;
    gene.push_back(0);
    for(int i = 1; i< size;++i)
    {
        int point = rand()%(size-1)+1;
        //所生成的每一代都是连通的
        if(map[gene[i-1]][point] == 0)
        {
            --i;
            continue;
        }
        gene.push_back(point);
        if(gene[i] == size-1)
        {
            return gene;
        }
    }
    return gen_gene(size);
}

//计算适应度
int cal_score(vector<int> gene_data)
{
    int score = 0;
    //没经过一个必经点，加 1
    for(int i = 0;i< mP.size();++i)
    {
        if(find(gene_data.begin(), gene_data.end(), mP[i])!=gene_data.end())
        {
            ++score;
        }
    }
    //没经过一个必经边，加 1
    for(int i = 0;i < mE.size(); ++i)
    {
        for(int j = 1;j<gene_data.size();++j)
        {
            if((gene_data[j-1] == mE[i].first && gene_data[j]==mE[i].second) || \
               (gene_data[j-1] == mE[i].second && gene_data[j]==mE[i].first))
            {
                ++score;
                break;
            }
        }
    }
    return score;
}

//比较路程大小
bool compDistance(const gene &a,const gene &b)
{
    return a.distance < b.distance;
}

//计算路程
int cal_distance(vector<int> a)
{
    int distance = 0;
    for(int i = 1;i<a.size();++i)
    {   //根据邻接矩阵查找到距离并相加
        distance += map[a[i-1]][a[i]];
    }
    return distance;
}

//交叉互换
vector<int> crossover(vector<int> &a, vector<int> &b, float mut_rate)
{
    vector<int> tmp;
    float rnd;
    for(int i = (int)min(a.size(), b.size()); i >= 0; --i)
    {
        rnd = (rand() % 100) / 100;
        if(rnd < mut_rate)
        {
            tmp = gen_gene(len);
        }
        else if(rnd > 0.5 + mut_rate/2)
        {
            tmp[i] = a[i]; // 选择父代基因片段
        }
        else
        {
            tmp[i] = b[i]; // 选择母代基因片段
        }
    }
    return tmp;
}
