// cartidge recycling
int maxParksItems(int cartidges, int dollars, int recReward, int perkCost){
    int perks = 0;
    for(int i=0;i<cartidges;i++){
        if(dollars>=perkCost){
            dollars -= perkCost;
            perks++;
        }else
            dollars += recReward;
    }
    return perks;
}