#include "WorldManager.h"
#include <memory>

void WorldManager::InitializeRooms()
{
	Room* building = new Room("You are inside a building, a well house for a large spring.",
		{
			new KeyItem("Set of keys", "There are some keys on the ground here.", Object::KEYS, Obstacle::GATE),
			new Item("Tasty food", "There is food here.", Object::FOOD),
			new Item("Brass lantern", "There is a shiny brass lamp here.", Object::LAMP),
			new Item("Small bottle", "There is a bottle here.", Object::BOTTLE)
		}, false);
	rooms.push_back(building);
	building->exitDirection = Direction::WEST;
	buildingRoom = building;

	Room* endOfRoad = new Room("You are standing at the end of a road before a small brick building. Around you is a forest. A small stream flows out of the building and down a gully.", false);
	rooms.push_back(endOfRoad);
	endOfRoad->enterDirection = Direction::EAST;
	startRoom = endOfRoad;

	Room* hill = new Room("You have walked up a hill, still in the forest. The road slopes back down the other side of the hill. There is a building in the distance.", false);
	rooms.push_back(hill);

	Room* forestNear = new Room("You are in open forest near both a valley and a road.", false);
	rooms.push_back(forestNear);

	Room* forestSide = new Room("You are in open forest, with a deep valley to one side.", false);
	rooms.push_back(forestSide);

	Room* valley = new Room("You are in a valley in the forest beside a stream tumbling along a rocky bed.",
		{ new KeyItem("Water", "", Object::WATER, Obstacle::PLANT) }, false);
	rooms.push_back(valley);

	Room* outsideGrate = new Room("You are in a 20-foot depression floored with bare dirt. Set into the dirt is a strong steel grate mounted in concrete. A dry streambed leads into the depression.",
		false, new Blocker("There is a locked gate.", "the gate is closed.", "The gate is now open.", Obstacle::GATE, { Direction::DOWN }));
	outsideGrate->enterDirection = Direction::DOWN;
	rooms.push_back(outsideGrate);

	Room* belowGrate = new Room("You are in a small chamber beneath a 3x3 steel grate to the surface. A low crawl over cobbles leads inward to the west.", false);
	belowGrate->exitDirection = Direction::UP;
	rooms.push_back(belowGrate);

	Room* cobbleCrawl = new Room("You are crawling over cobbles in a low passage. There is a dim light at the east end of the passage.",
		{
			new Item("Wicker cage", "There is a small wicker cage discarded nearby.", Object::CAGE)
		}, false);
	rooms.push_back(cobbleCrawl);

	Room* debrisRoom = new Room("You are in a debris room filled with stuff washed in from the surface. A low wide passage with cobbles becomes plugged with mud and debris here, but an awkward canyon leads upward and west. A note on the wall says: magic word xyzzy.",
		{
			new KeyItem("Black rod", "A three foot black rod with a rusty star on an end lies nearby.", Object::ROD, Obstacle::VOID)
		}, true);
	rooms.push_back(debrisRoom);
	xyzzyTpRoom = debrisRoom;

	Room* slopingCanyon = new Room("You are in an awkward sloping east/west canyon.", true);
	rooms.push_back(slopingCanyon);

	Room* birdChamber = new Room("You are in a splendid chamber thirty feet high. The walls are frozen rivers of orange stone. An awkward canyon and a good passage exit from east and west sides of the chamber.",
		{
			new KeyItem("Little bird in cage", "A cheerful little bird is sitting here singing.", Object::BIRD, Obstacle::SNAKE)
		}, true);
	rooms.push_back(birdChamber);

	Room* smallPit = new Room("At your feet is a small pit breathing traces of white mist. An east passage ends here except for a small crack leading on. ", true);
	rooms.push_back(smallPit);

	Room* hallOfMist = new Room("You are at one end of a vast hall stretching forward out of sight to the west, filled with wisps of white mist that sway to and fro almost as if alive. Rough stone steps lead up to a passage at the top of a dome above you. A wide staircase runs downward into the darkness; a chill wind blows up from below. There are small passages to the north and south, and a small crack leads east.", true);
	rooms.push_back(hallOfMist);

	Room* nuggetRoom = new Room("This is a low room with a crude note on the wall. The note says: you won't get it up the steps.",
		{
			new TreasureItem("Large gold nugget", "There is a large sparkling nugget of gold here!", Object::GOLD)
		}, true);
	rooms.push_back(nuggetRoom);

	Room* eastBank = new Room("You are on the east bank of a fissure slicing clear across the hall.",
		true, new Blocker("The mist is quite thick here, and the fissure is too wide to jump.", "the fissure is too wide.", "A crystalline bridge now spans the fissure.", Obstacle::VOID, { Direction::WEST }));
	rooms.push_back(eastBank);

	Room* westBank = new Room("You are on the west side of the fissure in the Hall of Mist.",
		{
			new TreasureItem("Several diamonds", "There are diamonds here!", Object::DIAMONDS)
		}, true);
	rooms.push_back(westBank);

	Room* king = new Room("You are in the hall of the mountain king, with passages off in all directions.",
		true, new Blocker("A huge green fierce snake bars the way!", "the snake blocks the way.", "The little bird attacks the green snake, and in an astounding flurry drives the snake away.", Obstacle::SNAKE, { Direction::NORTH, Direction::EAST, Direction::SOUTH, Direction::SOUTHWEST }));
	rooms.push_back(king);

	Room* southSideChamber = new Room("You are in the south side chamber.",
		{
			new TreasureItem("Precious jewelry", "There precious jewelry here!", Object::JEWELS)
		}, true);
	rooms.push_back(southSideChamber);

	Room* lowPassage = new Room("You are in a low N/S passage at a hole in the floor. The hole goes down to an e/w passage. ",
		{
			new TreasureItem("Bars of silver", "There are bars of silver here!", Object::SILVER)
		}, true);
	rooms.push_back(lowPassage);

	Room* plughRoom = new Room("You are in a large room, with a passage to the south, a passage to the west, and a wall of broken rock to the east. There is a large Y2 on a rock in the room's center. ", true);
	rooms.push_back(plughRoom);
	plughTpRoom = plughRoom;

	Room* secretCanyon = new Room("You are in a secret canyon which here runs E/W. It crosses over a very thight canyon 15 feet below. If you go down you may not be able to get back up.", true);
	rooms.push_back(secretCanyon);

	Room* tightCanyon = new Room("You are at a wide place in a very tight canyon.", true);
	rooms.push_back(tightCanyon);

	Room* tallCanyon = new Room("You are in a tall E/W canyon. A low tight crawl goes 3 feet north and seems to open up.", true);
	rooms.push_back(tallCanyon);

	Room* swissCheeseRoom = new Room("You are in a room whose walls resemble Swiss cheese. Obvious passages go west, east, NE and NW. Part of the room is occupied by a large bedrock block.", true);
	rooms.push_back(swissCheeseRoom);

	Room* orientalRoom = new Room("This is the Oriental room. Ancient oriental cave drawings cover the walls.",
		{
			new TreasureItem("Ming vase", "There is a delicate, precious, Ming vase here!", Object::VASE)
		}, true);
	rooms.push_back(orientalRoom);

	Room* twoPit = new Room("You are in the Twopit room. The floor here is littered with thin rock slab, which make it easy to descend the pits. There is a large hole in the wall above the pit at the end of the room.",
		true, new Blocker("There is a plant asking for water.", "it's too high.", "The plant now reaches the ceiling.", Obstacle::PLANT, { Direction::UP }));
	rooms.push_back(twoPit);

	Room* giantRoom = new Room("You are in the giant room. The ceiling here is too high up for your lamp to show it. Cavernous passages lead east, north, and south. On the west wall is scrawled the inscription: fee fie foe foo [sic]. The passage here is blocked by a recent cave-in.",
		{
			new TreasureItem("Golden eggs", "There are some golden eggs here!", Object::EGG)
		}, true);
	rooms.push_back(giantRoom);

	building->AddConnection({
			nullptr,	// NW
			nullptr,	// N
			nullptr,	// NE
			nullptr,	// E
			nullptr,	// SE
			nullptr,	// S
			nullptr,	// SW
			endOfRoad,	// W
			nullptr,	// U
			nullptr	// D
		});

	endOfRoad->AddConnection({
			nullptr,	// NW
			forestSide,	// N
			nullptr,	// NE
			building,	// E
			nullptr,	// SE
			valley,		// S
			nullptr,	// SW
			hill,		// W
			hill,		// U
			nullptr		// D
		});

	hill->AddConnection({
			nullptr,	// NW
			nullptr,	// N
			nullptr,	// NE
			endOfRoad,	// E
			nullptr,	// SE
			forestSide,	// S
			nullptr,	// SW
			nullptr,	// W
			nullptr,	// U
			endOfRoad	// D
		});

	forestNear->AddConnection({
			nullptr,	// NW
			nullptr,	// N
			nullptr,	// NE
			valley,		// E
			nullptr,	// SE
			forestSide,	// S
			nullptr,	// SW
			nullptr,	// W
			nullptr,	// U
			nullptr		// D
		});

	forestSide->AddConnection({
			nullptr,	// NW
			forestNear,	// N
			nullptr,	// NE
			valley,		// E
			nullptr,	// SE
			endOfRoad,	// S
			nullptr,	// SW
			nullptr,	// W
			nullptr,	// U
			nullptr		// D
		});

	valley->AddConnection({
			nullptr,		// NW
			endOfRoad,		// N
			nullptr,		// NE
			nullptr,		// E
			nullptr,		// SE
			outsideGrate,	// S
			nullptr,		// SW
			forestSide,		// W
			nullptr,		// U
			nullptr			// D
		});

	outsideGrate->AddConnection({
			nullptr,	// NW
			valley,		// N
			nullptr,	// NE
			nullptr,	// E
			nullptr,	// SE
			nullptr,	// S
			nullptr,	// SW
			nullptr,	// W
			nullptr,	// U
			belowGrate	// D
		});

	belowGrate->AddConnection({
			nullptr,		// NW
			nullptr,		// N
			nullptr,		// NE
			nullptr,		// E
			nullptr,		// SE
			nullptr,		// S
			nullptr,		// SW
			cobbleCrawl,	// W
			outsideGrate,	// U
			nullptr			// D
		});

	cobbleCrawl->AddConnection({
			nullptr,	// NW
			nullptr,	// N
			nullptr,	// NE
			belowGrate,	// E
			nullptr,	// SE
			nullptr,	// S
			nullptr,	// SW
			debrisRoom,	// W
			nullptr,	// U
			nullptr		// D
		});

	debrisRoom->AddConnection({
			nullptr,		// NW
			nullptr,		// N
			nullptr,		// NE
			cobbleCrawl,	// E
			nullptr,		// SE
			nullptr,		// S
			nullptr,		// SW
			slopingCanyon,	// W
			slopingCanyon,	// U
			nullptr			// D
		});

	slopingCanyon->AddConnection({
			nullptr,		// NW
			nullptr,		// N
			nullptr,		// NE
			debrisRoom,		// E
			nullptr,		// SE
			nullptr,		// S
			nullptr,		// SW
			birdChamber,	// W
			nullptr,		// U
			debrisRoom		// D
		});

	birdChamber->AddConnection({
			nullptr,		// NW
			nullptr,		// N
			nullptr,		// NE
			slopingCanyon,	// E
			nullptr,		// SE
			nullptr,		// S
			nullptr,		// SW
			smallPit,		// W
			nullptr,		// U
			nullptr			// D
		});

	smallPit->AddConnection({
			nullptr,		// NW
			nullptr,		// N
			nullptr,		// NE
			birdChamber,	// E
			nullptr,		// SE
			nullptr,		// S
			nullptr,		// SW
			nullptr,		// W
			nullptr,		// U
			hallOfMist		// D
		});

	hallOfMist->AddConnection({
			nullptr,	// NW
			king,		// N
			nullptr,	// NE
			smallPit,	// E
			nullptr,	// SE
			nuggetRoom,	// S
			nullptr,	// SW
			eastBank,	// W
			smallPit,	// U
			king		// D
		});

	nuggetRoom->AddConnection({
			nullptr,	// NW
			hallOfMist,	// N
			nullptr,	// NE
			nullptr,	// E
			nullptr,	// SE
			nullptr,	// S
			nullptr,	// SW
			nullptr,	// W
			nullptr,	// U
			nullptr		// D
		});

	eastBank->AddConnection({
			nullptr,	// NW
			nullptr,	// N
			nullptr,	// NE
			hallOfMist,	// E
			nullptr,	// SE
			nullptr,	// S
			nullptr,	// SW
			westBank,	// W
			nullptr,	// U
			nullptr		// D
		});

	westBank->AddConnection({
			nullptr,	// NW
			nullptr,	// N
			nullptr,	// NE
			eastBank,	// E
			nullptr,	// SE
			nullptr,	// S
			nullptr,	// SW
			nullptr,	// W
			nullptr,	// U
			nullptr		// D
		});

	king->AddConnection({
			nullptr,			// NW
			lowPassage,			// N
			nullptr,			// NE
			hallOfMist,			// E
			nullptr,			// SE
			southSideChamber,	// S
			secretCanyon,		// SW
			nullptr,			// W
			hallOfMist,			// U
			nullptr				// D
		});

	southSideChamber->AddConnection({
			nullptr,	// NW
			king,		// N
			nullptr,	// NE
			nullptr,	// E
			nullptr,	// SE
			nullptr,	// S
			nullptr,	// SW
			nullptr,	// W
			nullptr,	// U
			nullptr		// D
		});

	lowPassage->AddConnection({
			nullptr,	// NW
			plughRoom,	// N
			nullptr,	// NE
			nullptr,	// E
			nullptr,	// SE
			king,		// S
			nullptr,	// SW
			nullptr,	// W
			nullptr,	// U
			nullptr		// D
		});

	plughRoom->AddConnection({
			nullptr,	// NW
			nullptr,	// N
			nullptr,	// NE
			hallOfMist,	// E
			nullptr,	// SE
			lowPassage,	// S
			nullptr,	// SW
			nullptr,	// W
			nullptr,	// U
			nullptr		// D
		});

	secretCanyon->AddConnection({
			nullptr,	// NW
			nullptr,	// N
			nullptr,	// NE
			king,		// E
			nullptr,	// SE
			nullptr,	// S
			nullptr,	// SW
			nullptr,	// W
			nullptr,	// U
			tightCanyon	// D
		});

	tightCanyon->AddConnection({
			nullptr,	// NW
			tallCanyon,	// N
			nullptr,	// NE
			nullptr,	// E
			nullptr,	// SE
			nullptr,	// S
			nullptr,	// SW
			nullptr,	// W
			nullptr,	// U
			nullptr		// D
		});

	tallCanyon->AddConnection({
			nullptr,			// NW
			swissCheeseRoom,	// N
			nullptr,			// NE
			nullptr,			// E
			nullptr,			// SE
			tightCanyon,		// S
			nullptr,			// SW
			nullptr,			// W
			nullptr,			// U
			nullptr				// D
		});

	swissCheeseRoom->AddConnection({
			orientalRoom,	// NW
			nullptr,		// N
			nullptr,		// NE
			nullptr,		// E
			nullptr,		// SE
			tallCanyon,		// S
			nullptr,		// SW
			twoPit,			// W
			nullptr,		// U
			nullptr			// D
		});

	orientalRoom->AddConnection({
			nullptr,			// NW
			nullptr,			// N
			nullptr,			// NE
			nullptr,			// E
			swissCheeseRoom,	// SE
			nullptr,			// S
			nullptr,			// SW
			nullptr,			// W
			nullptr,			// U
			nullptr				// D
		});

	twoPit->AddConnection({
			nullptr,			// NW
			nullptr,			// N
			nullptr,			// NE
			swissCheeseRoom,	// E
			nullptr,			// SE
			nullptr,			// S
			nullptr,			// SW
			nullptr,			// W
			giantRoom,			// U
			nullptr				// D
		});

	giantRoom->AddConnection({
			nullptr,		// NW
			nullptr,		// N
			nullptr,		// NE
			nullptr,		// E
			nullptr,		// SE
			nullptr,		// S
			nullptr,		// SW
			nullptr,		// W
			secretCanyon,	// U
			twoPit			// D
		});
}
