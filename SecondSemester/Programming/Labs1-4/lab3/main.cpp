#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

const int H = 21;
const int W = 21;

const int ts = 50;

String TileMap[H] = {
"AAAAAAAAAAAAAAAAAAAAA",
"A   A       A     A A",
"A A AAA AAA AAA A A A",
"A A     A     A A A C",
"A AAA AAA A A A AAA A",
"A   A   A A A   A   A",
"AAA AAAAA A AAAAA A A",
"A   A     A     A A A",
"A AAA A AAAAAAA A AAA",
"A A A A   A   A     A",
"AAA A AAA AAA AAAAA A",
"A   A   A   A   A   A",
"AAA AAA AAA AAA A AAA",
"A     A   A   A A A A",
"A AAAAA A AAAAA AAA A",
"A A     A A     A   A",
"A A A AAAAA AAAAA AAA",
"A   A   A A   A   A A",
"AAA AAA A AAA A A A A",
"A   A           A   A",
"AAAAAAAAAAAAAAAAAAAAA",
};

float OffsetX = 0;
float OffsetY = ts * 14;

bool pob = false;
int pe = 2;




class Stopwatch {
public:
	Sprite min[2], sec[2], toc;
	int m[2], s[2], ms;

	Stopwatch(Texture& image) {
		for (int i = 0; i < 2; i++) {
			min[i].setTexture(image);
			sec[i].setTexture(image);

			min[i].setPosition(25 * i, 5);
			sec[i].setPosition(75 + 25 * i, 5);

			min[i].setTextureRect(IntRect(0, 0, 25, 36));
			sec[i].setTextureRect(IntRect(0, 0, 25, 36));

			m[i] = 0;
			s[i] = 0;
		}

		toc.setTexture(image);
		toc.setPosition(50, 5);
		toc.setTextureRect(IntRect(250, 0, 25, 36));

		ms = 0;
	}

	void update() {
		if (!pob && pe == 1)
			ms++;

		if (ms >= 1000) {
			s[1]++;
			ms = 0;
		}

		if (s[1] == 10) {
			s[0]++;
			s[1] = 0;
		}

		if (s[0] == 6) {
			m[1]++;
			s[0] = 0;
		}

		if (m[1] == 10) {
			m[0]++;
			m[1] = 0;
		}

		for (int i = 0; i < 2; i++) {
			sec[i].setTextureRect(IntRect(25 * s[i], 0, 25, 36));
			min[i].setTextureRect(IntRect(25 * m[i], 0, 25, 36));
		}
	}
};

int main() {
	RenderWindow window(VideoMode(7 * ts, 7 * ts), "Maze!");

	Texture t;
	t.loadFromFile("002.png");
	Sprite plat(t);

	int x = 1, y = 19;
	int newx = 0, newy = 0;
	TileMap[y][x] = 'B';
	int nx = 1, ny = 5;

	Texture w;
	w.loadFromFile("010.png");
	Sprite win(w);
	win.setPosition(20, 140);

	Texture ti;
	ti.loadFromFile("003.png");
	Stopwatch watch(ti);

	Texture p;
	p.loadFromFile("005.png");
	Sprite pause(p);
	pause.setPosition(80, 140);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed) {
				if (!pob) {
					if (pe == 1) {
						newx = x;
						newy = y;

						if (event.key.code == Keyboard::Right) {
							newx += 1;

							if (TileMap[newy][newx] == ' ')
								nx++;

							if (nx > 4) {
								OffsetX += ts;

								nx = 4;
							}
						}
						if (event.key.code == Keyboard::Left) {
							newx -= 1;

							if (TileMap[newy][newx] == ' ')
								nx--;

							if (nx < 2) {
								OffsetX -= ts;

								nx = 2;
							}
						}
						if (event.key.code == Keyboard::Up) {
							newy -= 1;

							if (TileMap[newy][newx] == ' ')
								ny--;

							if (ny < 2) {
								OffsetY -= ts;

								ny = 2;
							}
						}
						if (event.key.code == Keyboard::Down) {
							newy += 1;

							if (TileMap[newy][newx] == ' ')
								ny++;

							if (ny > 4) {
								OffsetY += ts;

								ny = 4;
							}
						}


					}

					if (event.key.code == Keyboard::Space) {
						pe++;

						if (pe == 3) {
							pe = 1;

						}

					}
				}
			}
		}

		if (TileMap[newy][newx] == ' ') {
			TileMap[y][x] = ' ';

			TileMap[newy][newx] = 'B';

			x = newx;
			y = newy;
		}
		if (TileMap[newy][newx] == 'C') {
			TileMap[y][x] = ' ';

			TileMap[newy][newx] = 'B';

			x = newx;
			y = newy;

			pob = true;

		}

		if (OffsetX < 0)
			OffsetX = 0;
		if (OffsetX > ts * 14)
			OffsetX = ts * 14;
		if (OffsetY < 0)
			OffsetY = 0;
		if (OffsetY > ts * 14)
			OffsetY = ts * 14;

		watch.update();
		window.clear(Color::White);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				if (TileMap[i][j] == 'A')
					plat.setTextureRect(IntRect(0, 0, ts, ts));
				if (TileMap[i][j] == 'B')
					plat.setTextureRect(IntRect(ts, 0, ts, ts));
				if (TileMap[i][j] == 'C')
					plat.setTextureRect(IntRect(ts * 2, 0, ts, ts));
				if (TileMap[i][j] == ' ')
					continue;

				plat.setPosition(j * ts - OffsetX, i * ts - OffsetY);

			}
		if (pob)

		for (int i = 0; i < 2; i++) {
			window.draw(watch.min[i]);
			window.draw(watch.sec[i]);
		}
		window.draw(watch.toc);
		if (pe == 2)

		window.display();
	}

	return 0;
}

