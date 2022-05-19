### Server Side Coordinates Transformation

```js
// --- unique the array elements ---
// Note: could be replaced by lodash library [ _.unique() ]
function onlyUnique(value, index, self) {
	return self.indexOf(value) === index;
}

let mapMetaCache_ = {};
const sizeOf = require('image-size');
const yaml = require('js-yaml');
const fs = require('fs');
fleet_state_sub.subscribe(function (_message) {
	// --- DATA ADAPTION --- 
	var maps = _message.robots.map(r => r.map).filter(onlyUnique);
	for (m of maps) {
		// --- exsting map meta-data case ---
		if (mapMetaCache_.hasOwnProperty(m)) { continue; }

		// --- no map meta-data in record case ---
		// --- read from <map_name>.yaml ---
		var meta = {};
		var mapDoc;
		try {
			mapDoc = yaml.load(fs.readFileSync(`/home/farobot/far_app_data/app_map/${m}.yaml`, 'utf8'));
			// console.log(mapDoc.origin);
			meta['origin'] = { x: mapDoc.origin[0], y: mapDoc.origin[1] };
			meta['resolution'] = mapDoc.resolution;
		} catch (e) {
			console.log(e);
		}

		// --- update map image height dimension ---
		var dimensions = {};
		try {
			dimensions = sizeOf(`/home/farobot/far_app_data/app_map/${m}.png`);
		}
		catch (e) {
			console.log(e);
		}
		meta['h'] = dimensions.height;
		mapMetaCache_[m] = meta;
	}
	// console.log(mapMetaCache_);

	for (let r of _message.robots) {
		var res = tfROS2Canvas(mapMetaCache_[r.map], { x: r.location.x, y: r.location.y });
		r.location.x = Math.round(res.x);
		r.location.y = Math.round(res.y);
	}
	// console.log(_message.robots);


	// --- update fleet messages ---
	fleet_fleet_obj_[_message.fleet_name] = { fleet_name: "", msg: {} };
	fleet_fleet_obj_[_message.fleet_name].fleet_name = _message.fleet_name;
	fleet_fleet_obj_[_message.fleet_name].robots = _message.robots;
	// console.log(fleet_fleet_obj_);

	topicMessages_["fleet_fleet_state"] = fleet_fleet_obj_;
});

// =================================
//     Coordinates Transfomation     
// =================================
function tfROS2Canvas(_mapDesc, _rosPos) {
	if (_mapDesc === undefined) { console.error('Map meta-data is not ready!'); return {}; }
	if (!(_mapDesc.hasOwnProperty('h'))) { console.error('Height of map is not defined!'); return {}; }
	if (!("origin" in _mapDesc)) { console.error('Origin of map is not loaded!'); return {}; }

	var xRosOffset = _mapDesc.origin.x / _mapDesc.resolution;
	var yRosOffset = _mapDesc.origin.y / _mapDesc.resolution;

	var xCanvas = (_rosPos.x / _mapDesc.resolution - xRosOffset).toFixed(0);
	var yCanvas = (_rosPos.y / _mapDesc.resolution - yRosOffset);
	// yCanvas = (Number(_mapDesc.h) - yCanvas).toFixed(0);
	yCanvas = (_mapDesc.h - yCanvas).toFixed(0);

	return {
		x: xCanvas,
		y: yCanvas
	};
}
```