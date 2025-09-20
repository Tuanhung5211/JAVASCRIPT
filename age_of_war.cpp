#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

struct UnitTemplate {
    string name;
    int cost;
    int atk;
    int hp;
};

struct Unit {
    string name;
    int atk;
    int hp;
};

struct PlayerState {
    string name;
    int baseHP;
    int age;    // 0..4
    int xp;     // currency
    vector<Unit> units;
};

vector<vector<UnitTemplate>> unitBank; // unitBank[age] -> list of templates

void initUnitBank() {
    // Age 0 (Caveman)
    unitBank.push_back({
        {"Tribal",  2, 2, 3},
        {"Slinger", 3, 3, 2}
    });
    // Age 1 (Medieval)
    unitBank.push_back({
        {"Swordsman", 4, 4, 4},
        {"Archer",    5, 5, 3}
    });
    // Age 2 (Renaissance)
    unitBank.push_back({
        {"Pikeman",   7, 6, 6},
        {"Musketeer", 8, 7, 4}
    });
    // Age 3 (Modern)
    unitBank.push_back({
        {"Rifleman",  10, 9, 6},
        {"TankLite",  12, 12, 10}
    });
    // Age 4 (Future)
    unitBank.push_back({
        {"Drone",     15, 14, 8},
        {"Mech",      20, 20, 18}
    });
}

void showStatus(const PlayerState &p, const PlayerState &op) {
    cout << "----------------------------------------\n";
    cout << p.name << " | Base HP: " << p.baseHP << " | Age: " << p.age << " | XP: " << p.xp << " | Units: " << p.units.size() << "\n";
    cout << op.name << "  | Base HP: " << op.baseHP << " | Age: " << op.age << " | XP: " << op.xp << " | Units: " << op.units.size() << "\n";
    cout << "Your units (front -> back): ";
    for (auto &u : p.units) cout << u.name << "(" << u.hp << ") ";
    cout << "\nEnemy units: ";
    for (auto &u : op.units) cout << u.name << "(" << u.hp << ") ";
    cout << "\n----------------------------------------\n";
}

void spawnUnit(PlayerState &p, int templateIndex) {
    auto &templ = unitBank[p.age][templateIndex];
    if (p.xp < templ.cost) {
        cout << "Khong du XP de spawn " << templ.name << ".\n";
        return;
    }
    p.xp -= templ.cost;
    p.units.push_back({templ.name, templ.atk, templ.hp});
    cout << p.name << " spawned " << templ.name << " (ATK " << templ.atk << " HP " << templ.hp << ")\n";
}

void addXPEveryTurn(PlayerState &p) {
    // Simple income: based on age
    p.xp += 3 + p.age; // e.g., age 0 -> +3xp, age4 -> +7xp
}

void resolveCombat(PlayerState &p1, PlayerState &p2) {
    // Front units fight
    if (!p1.units.empty() && !p2.units.empty()) {
        Unit &a = p1.units.front();
        Unit &b = p2.units.front();
        // simultaneous damage
        b.hp -= a.atk;
        a.hp -= b.atk;
        cout << p1.name << "'s " << a.name << " deals " << a.atk << " to " << p2.name << "'s " << b.name << "\n";
        cout << p2.name << "'s " << b.name << " deals " << b.atk << " to " << p1.name << "'s " << a.name << "\n";
        if (a.hp <= 0) {
            cout << p1.name << "'s " << a.name << " is destroyed.\n";
            p1.units.erase(p1.units.begin());
        }
        if (b.hp <= 0) {
            cout << p2.name << "'s " << b.name << " is destroyed.\n";
            p2.units.erase(p2.units.begin());
        }
    } else {
        // If one side has no units, other side units deal damage to base equal to sum of their atk
        if (p1.units.empty() && !p2.units.empty()) {
            int totalAtk = 0;
            for (auto &u : p2.units) totalAtk += u.atk;
            p1.baseHP -= totalAtk;
            cout << p2.name << " deals " << totalAtk << " damage to " << p1.name << "'s base!\n";
        } else if (!p1.units.empty() && p2.units.empty()) {
            int totalAtk = 0;
            for (auto &u : p1.units) totalAtk += u.atk;
            p2.baseHP -= totalAtk;
            cout << p1.name << " deals " << totalAtk << " damage to " << p2.name << "'s base!\n";
        }
    }
}

int aiChooseAction(PlayerState &ai, PlayerState &player) {
    // returns: 0=pass, 1=spawn, 2=upgrade
    // Basic AI strategy:
    // - If can upgrade and random chance, upgrade.
    // - Else try to spawn highest-cost unit affordable.
    // - Else pass.
    if (ai.age < 4) {
        int upgradeCost = 10 + ai.age * 5;
        if (ai.xp >= upgradeCost && (rand() % 100) < 30) {
            return 2;
        }
    }
    // try spawn best unit
    auto &pool = unitBank[ai.age];
    for (int i = (int)pool.size()-1; i>=0; --i) {
        if (ai.xp >= pool[i].cost) return 1*100 + i; // encode spawn with template idx
    }
    return 0;
}

void aiPerform(PlayerState &ai, PlayerState &player) {
    int choice = aiChooseAction(ai, player);
    if (choice == 0) {
        cout << ai.name << " passes.\n";
    } else if (choice == 2) {
        int upgradeCost = 10 + ai.age * 5;
        ai.xp -= upgradeCost;
        ai.age++;
        cout << ai.name << " upgrades to age " << ai.age << " (cost " << upgradeCost << ")\n";
    } else {
        int templateIndex = choice - 100;
        spawnUnit(ai, templateIndex);
    }
}

int main() {
    srand((unsigned)time(nullptr));
    initUnitBank();

    PlayerState player{"Player", 50, 0, 10, {}};
    PlayerState ai{"AI", 50, 0, 10, {}};

    cout << "==== Mini Age of War (Console) ====\n";
    cout << "Base HP start: 50 | Starting XP: 10\n";
    cout << "Commands each turn: spawn unit, upgrade age, or pass.\n";

    while (player.baseHP > 0 && ai.baseHP > 0) {
        // start of turn income
        addXPEveryTurn(player);
        addXPEveryTurn(ai);

        showStatus(player, ai);

        // Player action
        cout << "\nYour action:\n";
        cout << "1) Spawn unit\n2) Upgrade age\n3) Pass\nChoice: ";
        int choice; cin >> choice;
        if (choice == 1) {
            auto &pool = unitBank[player.age];
            cout << "Available units (age " << player.age << "):\n";
            for (int i=0;i<(int)pool.size();i++) {
                cout << i << ") " << pool[i].name << " - cost " << pool[i].cost << " | ATK " << pool[i].atk << " HP " << pool[i].hp << "\n";
            }
            cout << "Choose index: ";
            int idx; cin >> idx;
            if (idx < 0 || idx >= (int)pool.size()) {
                cout << "Invalid index. Turn wasted.\n";
            } else {
                spawnUnit(player, idx);
            }
        } else if (choice == 2) {
            if (player.age >= 4) {
                cout << "Ban da o luc lai cao nhat.\n";
            } else {
                int upgradeCost = 10 + player.age * 5;
                if (player.xp >= upgradeCost) {
                    player.xp -= upgradeCost;
                    player.age++;
                    cout << "Ban da nang cap len age " << player.age << " (cost " << upgradeCost << ")\n";
                } else {
                    cout << "Khong du XP de upgrade (cost " << upgradeCost << ")\n";
                }
            }
        } else {
            cout << "You pass.\n";
        }

        // AI action
        aiPerform(ai, player);

        // Combat resolution (both sides)
        resolveCombat(player, ai);
        resolveCombat(ai, player); // second call handles case where now one side has no units -> deal damage to base

        // small pause for readability
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    if (player.baseHP <= 0 && ai.baseHP <= 0) {
        cout << "Hoa! ca hai can cu deu bi pha huy.\n";
    } else if (player.baseHP <= 0) {
        cout << "Ban thua! AI pha huy can cu cua ban.\n";
    } else {
        cout << "Chuc mung! Ban da pha huy can cu AI.\n";
    }

    return 0;
}

