#include <stdio.h>
#include <stdlib.h>

/* 商品结构 */
typedef struct _prop{
	int id;				//道具编号 
	char name[50];		//道具名称 
	double price;		//道具价格 
	int stock;			//库存量（如果在背包中，表示道具数量） 
	char desc[200];		//道具描述 
}Prop;

/* 背包结构 */ 
typedef struct _bag{
	int PlayerId;		//所属玩家编号 
	int count;			//背包目前道具数量 
	int max;			//背包最大道具数量 
	Prop prop[8];		//背包目前道具数组 
}Bag;

/* 玩家结构 */
typedef struct _player{
	int id;				//玩家编号 
	char name[50];		//玩家名称 
	char pass[50];		//玩家密码 
	Bag bag;			//玩家背包 
	double gold;		//玩家金币（人性显示，及时转换铜币银币金币）	
	double zuanshi;		//玩家钻石 
}Player;

/* 声明函数 */
Prop *props;
Player *players;
int propCount = 0, playerCount = 0;	//计数 
void Init();			//初始化游戏数据 
void ShowProp();
void ShowPlayer();
 
int main(){
	//1.初始化数据
	Init();
	//2.打印初始化数据 
	ShowProp();
	return 0;
}

void Init(){
	static Prop propArray[] = {			//道具商店 
		{1, "双倍经验卡", 3000, 10, "让你打一把得到两把的钱钱！"},
		{2, "腐烂的道袍", 5000,  4, "只可远观，不可近战"}, 
		{3, "生锈的铁剑", 8000, 10, "好歹也是把武器，不是么"}, 
		{4, "无极袍",    18888,  2, "挨打，我是专业的"}, 
		{5, "直升一级丹",66666, 10, "吃了之后还想吃（30级前有用）"}, 
	}; 
	props = propArray;					//设定指针指向 
	//propCount = sizeof(propArray) / sizeof(Prop);
	propCount = 5;
	
	static Player playerArray[] = {		//玩家初始化 
		{1, "超级毛毛虫",	 "123456", .gold=50000,},
		{2, "泰罗奥特曼", 	 "123456", .gold=150000,},
		{3, "元始天尊之徒",  "123456", .gold=250000,},
		{4, "星河",          "123456", .gold=550000,}
	}; 
	players = playerArray;
	//playerCount = sizeof(playerArray) / sizeof(Player);
	playerCount = 4;
	
}
void ShowProp(){
	int i;
	if(props == NULL)
		return;
	printf("%-6s%-15s单价\t库存\t商品介绍\n", "编号", "名称");
	for(i=0; i<propCount; i++){
		printf("%-6d%-15s%.2lf\t%d\t%s\n", props[i].id, props[i].name, props[i].price, props[i].stock, props[i].desc);
	} 
}
  
