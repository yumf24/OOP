class Player{
    private:
        Weapon* weapon;
        Tool* tool;

    public:
        float getWeaponValue(int level);
        float getToolValue();
        void enhanceWeapon();
        void sealTool();
    };